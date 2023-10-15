# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lseghier <lseghier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 06:48:53 by lseghier          #+#    #+#              #
#    Updated: 2023/10/15 04:41:53 by lseghier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		:=		srcs
OBJ_DIR		:=		objs
LIBFT_DIR	=		libft
NAME		=		fractol
SRC			=		srcs/colors.c srcs/event.c srcs/fractol.c srcs/utils.c srcs/msg.c srcs/init.c srcs/parse_args \
					srcs/colors_utils.c \
					srcs/fractales_mods/burning_ship.c srcs/fractales_mods/julia.c srcs/fractales_mods/mandelbrot.c \

OBJ			=		$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
LIBFT		=		libft/libft.a
CC			=		cc
CPPFLAGS	=		-I./includes -I./libft/include
MLX			=		-L./minilibx-linux
MLXFLAGS	=		-lmlx -lX11 -lXext
CFLAGS		=		-Wall -Werror -Werror -g3

$(NAME):			$(OBJ)
						$(MAKE) -C $(LIBFT_DIR)
						$(CC) $(CFLAGS) $(CPPFLAGS) $(MLX) -lm $(OBJ) $(MLXFLAGS) -o $(NAME) $(LIBFT)

$(OBJ_DIR):
					mkdir -p $@
					mkdir -p fractales_mods

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

all:				$(NAME)

clean:
					rm -rf $(OBJ_DIR)
					$(MAKE) clean -C $(LIBFT_DIR)

fclean:				clean
						rm -f $(NAME)
						$(MAKE) fclean -C $(LIBFT_DIR)

re:					fclean all

.PHONY:				all clean fclean re
