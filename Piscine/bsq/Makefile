# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdaniel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/23 09:26:12 by bdaniel           #+#    #+#              #
#    Updated: 2016/07/23 09:26:15 by bdaniel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	bsq

SRC		=	./main.c\
			./srcs/get_input.c\
			./srcs/get_map.c\
			./srcs/get_file_utils.c\
			./srcs/solve_bsq.c\
			./srcs/print_result.c\

LIB		=	./srcs/libft.a\

HEADER	=	./includes

OBJ		=	$(SRC:.c=.o)

CC		=	@gcc

CFLAGS	=	-Wall -Wextra -Werror -I $(HEADER)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
