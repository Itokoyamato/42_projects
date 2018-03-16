# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 16:28:58 by dthuilli          #+#    #+#              #
#    Updated: 2016/11/02 16:36:41 by dthuilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c

HEADERS = ./includes/

SRC_COMPILED = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c -I $(HEADERS) $(SRC)
	ar rc $(NAME) $(SRC_COMPILED)
	ranlib libft.a

clean:
	/bin/rm -f $(SRC_COMPILED)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
	