# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/21 05:24:40 by lseghier          #+#    #+#              #
#    Updated: 2023/09/21 05:36:41 by lseghier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fract-ol

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

MLX_PATH	= ./minilibx-linux
MLX_NAME	= libmlx.a
MLX		= $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH	= ./libft
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

INCLUDES	= -I./includes -I./$(MLX_PATH) -I./$(LIBFT_PATH)

SRCS_PATH	= srcs/
SRC			= fractol.c \
			  event.c \
			  color.c \
			  utils.c \
			  fractales_mods/mandelbrot.c \
			  fractales_mods/julia.c \
			  fractales_mods/burningship.c \
SRCS		= $(addprefix $(SRCS_PATH), $(SRC))

OBJS_PATH	= objs/
OBJS		= $(SRC:.c=.o)
OBJ			= $(addprefix $(OBJS_PATH), $(OBJS))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ $(INC)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)
	@mkdir -p $(OBJS_PATH)fractales_mods

$(MLX):
	@make -C $(MLX_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJS_PATH) $(OBJ)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) $(MLX) -lXext -lX11 -lm -o $(NAME)
	@echo "Fractol ready."

bonus: all

clean:
	@echo "Removing .o obj files..."
	@rm -rf $(OBJS_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@echo "Removing fractol..."
	@rm -rf $(NAME)
	@make clean -C $(MLX_PATH)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re bonus
