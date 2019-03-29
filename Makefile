# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 16:52:52 by lbonnete          #+#    #+#              #
#    Updated: 2019/03/29 14:36:40 by lbonnete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Wextra -Werror -O2

SRC = src/main.c src/dealers.c src/dealers_2.c src/deal_key.c src/info_edit.c src/mandelbrot.c src/font.c src/mandelbrot_3.c src/display.c src/tools_2.c src/tools.c src/julia.c src/julia_3.c src/hud.c

OBJ = main.o dealers.o dealers_2.o deal_key.o info_edit.o mandelbrot.o font.o mandelbrot_3.o display.o tools.o julia.o julia_3.o hud.o tools_2.o

SRCDIR = src

OBJDIR = obj

INC = inc/fractol.h

all: $(NAME) 

$(NAME):
	gcc $(FLAGS) -c $(SRC) -I $(INC)
	gcc -o $(NAME) -I /usr/local/include  $(OBJ) -L /usr/local/lib/ -l mlx -framework OpenGL -framework AppKit -lpthread
	mv $(OBJ) $(OBJDIR)
	echo "Fractol ready"

p: all clean

clean:
	/bin/rm -f $(OBJDIR)/*
	echo "Objects Destroyed"

fclean:	clean
	/bin/rm -f $(NAME)
	echo "Project Destroyed"

re:	fclean all

norm:
	norminette $(SRC) $(INC)

.PHONY:	all clean fclean re norm p

.SILENT: