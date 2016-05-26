##
## Makefile for minishell in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
##
## Made by Gaëtan Léandre
## Login   <leandr_g@epitech.net>
##
## Started on  Sat Jan 23 02:23:24 2016 Gaëtan Léandre
## Last update Tue Apr 12 18:24:42 2016 Gaëtan Léandre
##

NAME	=	42sh

SRC	=	src/main.c			\
		src/list.c			\
		src/get_next_line.c		\
		src/builds.c			\
		src/free.c			\
		src/pars_env.c			\
		src/str_to_wordtab.c		\
		src/utils.c			\
		src/my_getnbr.c			\
		src/utils2.c			\
		src/list2.c			\
		src/pipe.c			\
		src/sighandler.c		\
		src/modular_var.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Werror -Wall -Wextra		\
		-W -ansi -pedantic		\
		-Iinclude -g3

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc $(OBJ) -o $(NAME)

clean	:
		rm -rf $(OBJ)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean all
