# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkubanyc <tkubanyc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/25 10:54:09 by tkubanyc          #+#    #+#              #
#    Updated: 2024/06/10 14:35:44 by tkubanyc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME	:= fractol
BONUS	:= fractol_bonus
CC		:= cc
CFLAGS	:= -Wextra -Wall -Werror -Ofast
LIBMLX	:= ./lib/mlx42

# Include directories
INCLUDES	:= -I ./include -I ./lib/libft -I $(LIBMLX)/include
LIBS		:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

# Mandatory Source and Object files
SRC_DIR	:= src
OBJ_DIR	:= obj
SRC		:= $(SRC_DIR)/fractol.c \
			$(SRC_DIR)/input_handler.c \
			$(SRC_DIR)/fractol_init.c \
			$(SRC_DIR)/fractol_render.c \
			$(SRC_DIR)/action_listener.c \
			$(SRC_DIR)/action_events.c \
			$(SRC_DIR)/exit_handler.c \
			$(SRC_DIR)/fractol_utils.c

OBJ := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Bonus Source and Object files
BONUS_SRC_DIR	:= src_bonus
BONUS_SRC		:= $(BONUS_SRC_DIR)/fractol_bonus.c \
					$(BONUS_SRC_DIR)/input_handler_bonus.c \
					$(BONUS_SRC_DIR)/fractol_init_bonus.c \
					$(BONUS_SRC_DIR)/fractol_render_bonus.c \
					$(BONUS_SRC_DIR)/action_listener_bonus.c \
					$(BONUS_SRC_DIR)/events_keyboard_bonus.c \
					$(BONUS_SRC_DIR)/events_mouse_bonus.c \
					$(BONUS_SRC_DIR)/events_window_bonus.c \
					$(BONUS_SRC_DIR)/exit_handler_bonus.c \
					$(BONUS_SRC_DIR)/fractol_utils_bonus.c

BONUS_OBJ := $(patsubst $(BONUS_SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(BONUS_SRC))

# Headers
HEADER := include/fractol.h
HEADER_BONUS := include/fractol_bonus.h

# Libft
LIBFT_DIR	:= ./lib/libft
LIBFT		:= $(LIBFT_DIR)/libft.a
PRINTF_DIR	:= $(LIBFT_DIR)/ft_printf
PRINTF		:= $(PRINTF_DIR)/libftprintf.a

# Rules
all: clone_submodules libmlx $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT) $(PRINTF) $(LIBS)

clone_submodules:
	@if [ ! -d "$(LIBMLX)" ]; then \
		git submodule update --init --recursive; \
	fi

libmlx:
	@if [ ! -d "$(LIBMLX)" ]; then \
		if [ -f .gitmodules ]; then \
			url=$$(grep -A 1 'lib/mlx42' .gitmodules | grep 'url =' | awk '{print $$3}'); \
			if [ -n "$$url" ]; then \
				git clone "$$url" "$(LIBMLX)"; \
			else \
				echo "Error: URL for MLX42 not found in .gitmodules"; \
				exit 1; \
			fi; \
		else \
			echo "Error: .gitmodules file not found"; \
			exit 1; \
		fi; \
	fi
	@if [ ! -d "$(LIBMLX)/build" ]; then \
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4; \
	fi

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"

$(OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< && printf "Compiling: $(notdir $<)\n"

bonus: clone_submodules libmlx $(LIBFT) $(PRINTF) $(BONUS)

$(BONUS): $(BONUS_OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) -o $@ $(BONUS_OBJ) $(LIBFT) $(PRINTF) $(LIBS)

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@printf "Cleaning: object files and libft\n"

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@rm -rf $(LIBMLX)/build
	@printf "Full cleaning: executable and libraries\n"

re: fclean all

.PHONY: all clean fclean re bonus libmlx clone_submodules
