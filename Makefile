# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aboiarin <aboiarin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 18:09:10 by aboiarin          #+#    #+#              #
#    Updated: 2023/11/23 18:18:04 by aboiarin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

NAME = fractol

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

MLBX_PATH = ./minilibx-linux
MLBX = $(MLBX_PATH)/libmlx.a

SRC = fractol.c

OBJ = $(SRC:.c=.o)

all: start_message $(NAME) success_message

bonus: all

.o:	.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(LIBFT) $(MLBX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	@echo 'Compiling libft... 📀'
	@make -C $(LIBFT_PATH) all
	@echo 'libft done ✅'

$(MLBX):
	@echo 'Compiling MiniLibX... 🪄'
	@make -C $(MLBX_PATH) all
	@echo 'MiniLibX done ✅'
	
clean:
	@$(RM) $(OBJ)
	@make -C $(LIBFT_PATH) clean
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
