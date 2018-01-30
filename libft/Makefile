# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 12:47:36 by llaporte          #+#    #+#              #
#    Updated: 2018/01/30 15:29:19 by dthuilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJDIR = obj/

STD = ft_abs.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_ctowc.c \
		ft_gnl.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isstrdigit.c \
		ft_islower.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_isupper.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_iutoa_base.c \
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
		ft_nbrlen.c \
		ft_negnull.c \
		ft_pow.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_putwchar.c \
		ft_putwchar_fd.c \
		ft_putwstr.c \
		ft_putwstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_strerase.c \
		ft_strinsert.c \
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
		ft_strtoupper.c \
		ft_strtolower.c \
		ft_strtowstr.c \
		ft_strtrim.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_uitoa_base.c \
		ft_unbrlen.c \
		ft_wcharsize.c \
		ft_wstrinsert.c \
		ft_wstrjoin.c \
		ft_wstrlen.c \
		ft_wstrsub.c \

PRINTF = ft_printf.c \
			printf_helpers.c \
			printf_parsers.c \
			printf_conv_general.c \
			printf_conv_numbers.c \
			parse_utils.c \

SRCS = $(addprefix srcs/std/, $(STD)) $(addprefix srcs/printf/, $(PRINTF))

OBJ = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@echo "Compiling $@"
	@gcc -Wall -Wextra -Werror -I includes -o3 -c $< -o $@

$(NAME): $(OBJ)
	@echo "Create $(NAME)..."
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) is fully created!"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libft.h.gch

re: fclean all
