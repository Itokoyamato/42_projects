# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/09 15:39:04 by dthuilli          #+#    #+#              #
#    Updated: 2018/02/07 16:48:40 by dthuilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= lem-in

# src / obj files
SRC		=	main.c \
			parser.c \
			parser_rooms.c \
			parser_tunnels.c \
			parser_utils.c \
			solver.c \
			ants_utils.c \
			roomlist_utils.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g3

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
	@printf "$(SILENT_COLOR)Compiling $<$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<
	@echo " $(OK_COLOR)✓ $(NO_COLOR)"

$(FT_LIB):
	@make -C $(FT_DIR)
	@echo "$(OK_COLOR)Done compiling libft ✓ $(NO_COLOR)"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(FT_LNK) -lm -o $(NAME)
	@echo "$(OK_COLOR)Done compiling lem_in ✓ $(NO_COLOR)"

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT_DIR) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT_DIR) fclean

re: fclean all
