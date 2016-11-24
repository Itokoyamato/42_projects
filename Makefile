# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaporte <llaporte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 12:47:36 by llaporte          #+#    #+#              #
#    Updated: 2016/11/24 16:14:41 by llaporte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

ODIR = out
SRCDIR = srcs
LIBFTDIR = libft/
INC = includes

SRC =	main.c \
		solver.c \
		map.c \
		get_list.c \
		check_list.c \
		test_utils.c \
		shrink.c \

SRCS = $(addprefix $(SRCDIR)/, $(SRC))
SRCSLIB = $(addprefix $(LIBFTDIR)/, $(SRCLIB))

OBJ = $(SRC:.c=.o)
OBJLIB = $(SRCLIB:.c=.o)

all: $(NAME)

$(NAME):
	make -C $(LIBFTDIR)
	gcc -o $(NAME) -Wall -Wextra -Werror $(SRCS) $(LIBFTDIR)libft.a -I $(INC)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

relib: fclean fcleanl all
