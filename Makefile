# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:23:53 by dthuilli          #+#    #+#              #
#    Updated: 2016/11/11 16:56:53 by dthuilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC		=	./ft_putchar.c			\
			./ft_putnbr.c			\
			./ft_putstr.c			\
			./ft_strcmp.c			\
			./ft_strlen.c			\
			./ft_strcat.c			\
			./ft_strncat.c			\
			./ft_strlcat.c			\
			./ft_strcpy.c			\
			./ft_strncpy.c			\
			./ft_strdup.c			\
			./ft_memset.c			\
			./ft_memcpy.c			\
			./ft_bzero.c			\
			./ft_isalpha.c			\
			./ft_isdigit.c			\
			./ft_isalnum.c			\
			./ft_isascii.c			\
			./ft_isprint.c			\
			./ft_toupper.c			\
			./ft_tolower.c			\
			./ft_putchar_fd.c		\
			./ft_putstr_fd.c		\
			./ft_putendl_fd.c		\
			./ft_putnbr_fd.c		\
			./ft_putendl.c			\
			./ft_strchr.c			\
			./ft_strrchr.c			\
			./ft_strstr.c			\
			./ft_strnstr.c			\
			./ft_strncmp.c			\
			./ft_atoi.c				\
			./ft_itoa.c				\
			./ft_memccpy.c			\
			./ft_memmove.c			\
			./ft_memchr.c			\
			./ft_memcmp.c			\
			./ft_memalloc.c			\
			./ft_memdel.c			\
			./ft_strnew.c			\
			./ft_strdel.c			\
			./ft_strclr.c			\
			./ft_striter.c			\
			./ft_striteri.c			\
			./ft_strmap.c			\
			./ft_strmapi.c			\
			./ft_strequ.c			\
			./ft_strnequ.c			\
			./ft_strsub.c			\
			./ft_strjoin.c			\
			./ft_strtrim.c			\
			./ft_strsplit.c			\
			./ft_lstnew.c			\
			./ft_lstdelone.c		\
			./ft_lstdel.c			\
			./ft_lstadd.c			\
			./ft_lstiter.c			\
			./ft_lstmap.c			\

SRC_COMPILED = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(SRC_COMPILED)
	ranlib $(NAME)

clean:
	/bin/rm -f $(SRC_COMPILED)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
	