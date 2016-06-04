##
## Makefile for minishell in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
##
## Made by Gaëtan Léandre
## Login   <leandr_g@epitech.net>
##
## Started on  Sat Jan 23 02:23:24 2016 Gaëtan Léandre
## Last update Sat Jun  4 12:51:33 2016 Kerdelhue Ethan
##

NAME	=	mysh

SRC	= 	main.c				\
		../src/utils/get_next_line.c	\
		../src/utils/str_to_wordtab.c	\
		sep.c				\
		epur.c				\
		opt.c				\
		link_list.c			\
		cmd.c				\
		my_strcat.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra		\
		-W -ansi -pedantic		\
		-I../inc -g3

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc $(OBJ) -o $(NAME)

clean	:
		rm -rf $(OBJ)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean all
