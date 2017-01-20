# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthuilli <dthuilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/09 13:08:23 by dthuilli          #+#    #+#              #
#    Updated: 2017/01/20 16:21:58 by dthuilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

# src / obj files
SRC		=	main.c \
			controls.c \
			controls_utils.c \
			update.c \
			init.c \
			map_parser.c \
			map_utils.c \
			image.c \
			math.c \
			draw.c \
			render.c \
			render_utils.c \
			color_hsv.c \
			color_rgba.c \
			color_palette.c \

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

# mlx library
MLX		= ./miniLibX/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./miniLibX
MLX_LNK	= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
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

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@printf "$(SILENT_COLOR)Compiling $<$(NO_COLOR)"
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<
	@echo " $(OK_COLOR)✓ $(NO_COLOR)"

$(FT_LIB):
	@make -C $(FT)

$(MLX_LIB):
	-@make -C $(MLX)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@make -C $(MLX) clean

fclean: clean
	@rm -rf $(NAME)
	@make -C $(FT) fclean

re: fclean all
