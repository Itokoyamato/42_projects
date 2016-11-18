# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 12:47:36 by llaporte          #+#    #+#              #
#    Updated: 2016/11/16 10:58:54 by dthuilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
NAMELIB = libft.a

ODIR = out
SRCDIR = srcs
LIBFTDIR = libft
INC = includes

SRCLIB =	ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_islower.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_isupper.c \
			ft_itoa.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_nbdigit.c \
			ft_pow.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstaddend.c \
			ft_lstcount.c \
			ft_lstrev.c \

SRC =	main.c \
		solver.c \
		map.c \
		test_tetriminos.c \
		test_tetriminos2.c \
		test_utils.c \

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
SRCSLIB = $(addprefix $(LIBFTDIR)/, $(SRCLIB))

OBJ = $(SRC:.c=.o)
OBJLIB = $(SRCLIB:.c=.o)

all: $(NAME)

libft/libft.a:
	gcc -c -Wall -Wextra -Werror $(SRCSLIB) -I $(INC)
	ar rc $(NAMELIB) $(OBJLIB)
	ranlib $(NAMELIB)

$(NAME): libft/libft.a
	gcc -o $(NAME) -Wall -Wextra -Werror $(SRCS) libft.a -I $(INC)

clean:
	rm -f $(OBJ)
	rm -f $(OBJLIB)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAMELIB)

re: fclean all
