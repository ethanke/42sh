##
## Makefile for minishell in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
##
## Made by Gaëtan Léandre
## Login   <leandr_g@epitech.net>
##
## Started on  Sat Jan 23 02:23:24 2016 Gaëtan Léandre
## Last update Wed May 25 16:52:16 2016 Ethan Kerdelhue
##

NAME	=	mysh

SRC	= 	main.c			\
		../src/get_next_line.c	\
		my_str_to_wordtab.c	\
		my_strcat.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Werror -Wall -Wextra		\
		-W -ansi -pedantic		\
		-I../include -g3

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc $(OBJ) -o $(NAME)

clean	:
		rm -rf $(OBJ)

fclean	:	clean
		rm -rf $(NAME)

re	:	fclean all
