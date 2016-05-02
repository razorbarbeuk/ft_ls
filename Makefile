# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/25 14:48:45 by gbourson          #+#    #+#              #
#    Updated: 2016/05/02 18:02:05 by gbourson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC_PATH = srcs

SRC_NAME = main.c ft_lst_ls.c ft_opt_ls.c ft_print_ls.c \
	  ft_space.c ft_sort.c ft_utils.c ft_error.c ft_create.c ft_open_dir.c\

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ = $(SRC_NAME:.c=.o)

INCLUDE = ./includes

CC = gcc
CFLAGS = -g -Werror -Wall -Wextra

all : $(NAME)

$(NAME) :
	@$(CC) $(CFLAGS) -c $(SRC) -I ./includes
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJ) -L . -I libft/includes -L libft/ -lft -o $(NAME)
	@rm -f $(OBJ)
	@echo "Tu as compilé !"

clean :
	@make -C libft clean
	@rm -f $(OBJ)
	@echo "Tu as clean !"

fclean : clean
	@make -C libft fclean
	@rm -f $(NAME)
	@echo "C'est encore plus propre..."

re : fclean all

.PHONY: all, clean, fclean, re
