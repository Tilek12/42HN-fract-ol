# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 10:54:09 by tkubanyc          #+#    #+#              #
#    Updated: 2024/06/05 15:39:24 by tkubanyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME	:= fractol
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror -O3
LIBMLX	:= ./lib/MLX42

# Include directories
INCLUDES	:= -I ./include -I ./lib/libft -I $(LIBMLX)/include -I ../../../LeakSanitizer
LIBS		:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -L ../../../LeakSanitizer -llsan -lc++  -Wno-gnu-include-next

# Source and Object files
SRC_DIR	:= src
OBJ_DIR	:= obj
SRCS	:= $(SRC_DIR)/main.c \
			$(SRC_DIR)/input_handler.c \
			$(SRC_DIR)/fractol_init.c \
			$(SRC_DIR)/fractol_render.c \
			$(SRC_DIR)/action_listener.c \
			$(SRC_DIR)/fractol_utils.c \
			$(SRC_DIR)/error_handler.c
OBJS	:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Header
HEADER = include/fractol.h

# Libft
LIBFT_DIR	:= ./lib/libft
LIBFT		:= $(LIBFT_DIR)/libft.a
PRINTF_DIR	:= $(LIBFT_DIR)/ft_printf
PRINTF		:= $(PRINTF_DIR)/libftprintf.a
GNL_SRCS	:= $(LIBFT_DIR)/ft_get_next_line/get_next_line.c \
			$(LIBFT_DIR)/ft_get_next_line/get_next_line_utils.c
GNL_OBJS	:= $(patsubst $(LIBFT_DIR)/ft_get_next_line/%.c, $(OBJ_DIR)/ft_get_next_line/%.o, $(GNL_SRCS))

# Rules
all: libmlx $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF) $(GNL_OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(GNL_OBJS) $(LIBFT) $(PRINTF) $(LIBS)

libmlx:
	@if [ ! -d "$(LIBMLX)/build" ]; then \
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4; \
	fi

$(OBJ_DIR)/ft_get_next_line/%.o: $(LIBFT_DIR)/ft_get_next_line/%.c | $(OBJ_DIR)/ft_get_next_line
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/ft_get_next_line:
	@mkdir -p $(OBJ_DIR)/ft_get_next_line

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@rm -rf $(LIBMLX)/build
	@printf "Cleaning: object files and libft\n"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@printf "Full cleaning: executable and libraries\n"

re: fclean all

.PHONY: all clean fclean re libmlx
