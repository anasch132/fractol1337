# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achatoua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/31 21:58:16 by achatoua          #+#    #+#              #
#    Updated: 2019/07/31 21:58:40 by achatoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./srcs/
INC_PATH = ./includes/ $(LIB_PATH)/includes/
OBJ_PATH = ./obj/

LIB_LNK	= -lmlx -framework OpenGL -framework AppKit 

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_NAME = colors.c			\
		   mandelbrot.c		\
		   events.c			\
		   init.c			\
		   keycode.c		\
		   keycode1.c		\
		   main.c			\
		   julia.c

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(LIB_LNK)
	@echo "Compiling" [ $(NAME) ]

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
	@echo "Linking" [ $< ]

clean:
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj Fractol..."

fclean: clean
	@rm -f $(NAME)
	@echo "Remove..." [ $(NAME) ]

re: fclean all
