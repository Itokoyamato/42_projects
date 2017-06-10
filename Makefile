# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/09 15:39:04 by dthuilli          #+#    #+#              #
#    Updated: 2017/06/10 13:29:12 by dthuilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= dthuilli.filler

# src / obj files
SRC		=	main.c \
			player.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

# ft library
FT_DIR		= ./libft/
FT_LIB	= $(addprefix $(FT_DIR),libft.a)
FT_INC	= -I ./libft/includes
FT_LNK	= -L ./libft -l ft

# directories
SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./obj/

# Colors
NO_COLOR     := \x1b[0m
OK_COLOR     := \x1b[32;01m
ERROR_COLOR  := \x1b[31;01m
WARN_COLOR   := \x1b[33;01m
SILENT_COLOR := \x1b[30;01m

all: obj $(FT_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@printf "$(WARN_COLOR)$(NAME): $(NO_COLOR)\n"
	@printf "$(SILENT_COLOR)Compiling $<$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<
	@echo " $(OK_COLOR)✓ $(NO_COLOR)"

$(FT_LIB):
	@make -C $(FT_DIR)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(FT_LNK) -lm -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT_DIR) fclean

re: fclean all
