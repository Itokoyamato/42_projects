# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmichaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/23 11:09:20 by jmichaud          #+#    #+#              #
#    Updated: 2016/07/24 15:53:19 by jmichaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	colle-2

SRC		=	./srcs/main.c\
			./srcs/check_colle.c\
			./srcs/ft_list_push_back.c\
			./srcs/is_colle00.c\
			./srcs/is_colle01.c\
			./srcs/is_colle02.c\
			./srcs/is_colle03.c\
			./srcs/is_colle04.c\
			./srcs/get_string.c\
			./srcs/is_valid.c\
			./srcs/colle_02.c\
			./srcs/ft_create_elem.c\
			./srcs/print_colle.c\

LIB		=	../../libft.a\

HEADER	=	./includes

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -I $(HEADER)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
