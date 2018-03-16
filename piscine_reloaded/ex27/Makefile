# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 17:04:34 by dthuilli          #+#    #+#              #
#    Updated: 2016/11/02 17:12:50 by dthuilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(NAME).c
	gcc -Wall -Wextra -Werror -o $(NAME) $(NAME).o

clean:
	/bin/rm -f $(NAME).o

fclean: clean
	/bin/rm -f $(NAME)
	