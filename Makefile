# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 10:54:09 by tkubanyc          #+#    #+#              #
#    Updated: 2024/05/26 14:46:12 by tkubanyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME	:= fractol
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42

# Include directories
INCLUDES	:= -I ./include -I ./lib/libft -I $(LIBMLX)/include
LIBS		:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Source and Object files
SRC_DIR	:= src
OBJ_DIR	:= obj
SRCS	:= $(SRC_DIR)/fractol.c
OBJS	:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Header
HEADER = includes/fractol.h

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
	@$(CC) $(CFLAGS) -o $@ $(OBJS) $(GNL_OBJS) $(LIBFT) $(PRINTF) $(LIBS) > /dev/null 2>&1

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build > /dev/null 2>&1 && make -C $(LIBMLX)/build -j4 > /dev/null 2>&1

$(OBJ_DIR)/ft_get_next_line/%.o: $(LIBFT_DIR)/ft_get_next_line/%.c | $(OBJ_DIR)/ft_get_next_line
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/ft_get_next_line:
	@mkdir -p $(OBJ_DIR)/ft_get_next_line

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR) > /dev/null 2>&1

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< && printf "Compiling: $(notdir $<)\n" > /dev/null 2>&1

clean:
	@rm -rf $(OBJ_DIR) > /dev/null 2>&1
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@$(MAKE) -C $(PRINTF_DIR) clean > /dev/null 2>&1
	@rm -rf $(LIBMLX)/build > /dev/null 2>&1
	@printf "Cleaning: object files and libft\n"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	@$(MAKE) -C $(PRINTF_DIR) fclean > /dev/null 2>&1
	@printf "Full cleaning: executable and libraries\n"

re: fclean all

.PHONY: all clean fclean re libmlx
