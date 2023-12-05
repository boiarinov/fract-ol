# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 18:09:10 by aboiarin          #+#    #+#              #
#    Updated: 2023/12/05 16:19:24 by aboiarin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

NAME = fractol

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = ./mlx
MLX = $(MLX_PATH)/libmlx.a

SRC = fractol.c get_colors.c

OBJ = $(SRC:.c=.o)

all: start_message $(NAME) success_message

bonus: all

.o:	.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx -03 -c $< -o $@

$(NAME):	$(LIBFT) $(MLX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -Lmlx -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	@echo 'Compiling libft... 📀'
	@make -C $(LIBFT_PATH) all
	@echo 'libft done ✅'

$(MLX):
	@echo 'Compiling MiniLibX... 🪄'
	@make -C $(MLX_PATH) all
	@echo 'MiniLibX done ✅'
	
clean:
	@$(RM) $(OBJ)
	@make -C $(LIBFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@echo 'Object files removed ✨'

start_message:
	@echo 'Compiling fractol... 🌈'

success_message:
	@echo 'All done ✅'

re_message:
	@echo 'Starting over... ⏪'

fclean:	clean
		@make -C $(LIBFT_PATH) fclean
		@$(RM) $(NAME)
		@echo 'Executables removed ✨'

re: re_message fclean all

.PHONY: all clean fclean re bonus
