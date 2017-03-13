# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 11:23:53 by dthuilli          #+#    #+#              #
#    Updated: 2017/01/20 16:12:43 by dthuilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRC		= $(shell ls | grep -E "ft_.+\.c")
OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

# Colors
NO_COLOR     := \x1b[0m
OK_COLOR     := \x1b[32;01m
ERROR_COLOR  := \x1b[31;01m
WARN_COLOR   := \x1b[33;01m
SILENT_COLOR := \x1b[30;01m

all: $(NAME)

%.o:%.c
	@printf "$(SILENT_COLOR)Compiling $<$(NO_COLOR)"
	@$(CC) $(CFLAGS) -I includes -o $@ -c $<
	@echo " $(OK_COLOR)✓ $(NO_COLOR)"

$(NAME): $(OBJ)
	@printf "$(SILENT_COLOR)Compiling $(NAME)$(NO_COLOR)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo " $(OK_COLOR)✓ $(NO_COLOR)"

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
	