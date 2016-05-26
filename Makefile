##
## Makefile for minishell in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
##
## Made by Gaëtan Léandre
## Login   <leandr_g@epitech.net>
##
## Started on  Sat Jan 23 02:23:24 2016 Gaëtan Léandre
## Last update Thu May 26 04:18:57 2016 Gaëtan Léandre
##

NAME	=	42sh

ECHO            =       /bin/echo -e
DEFAULT         =       "\033[00m"
GREEN           =       "\033[0;32m"
TEAL            =       "\033[1;36m"
RED             =       "\033[0;31m"

SRCDIR          =       src

BLTINDIR        =       $(SRCDIR)/builtin
LISTDIR         =       $(SRCDIR)/list
UTILSDIR        =       $(SRCDIR)/utils
PRTFDIR         =       $(SRCDIR)/my_printf
SPRTFDIR        =       $(SRCDIR)/my_sprintf

INCDIR          =       inc
LIBDIR          =       lib

RM              =       rm -f

CC              =       gcc
CFLAGS		=	-W -Wall -Wextra -Werror		\
			-ansi -pedantic				\
			-I$(INCDIR)

##  MAIN  ##
SRC             =       $(SRCDIR)/main.c

## LIST ##
SRC		+=	$(LISTDIR)/list.c			\
			$(LISTDIR)/list2.c

## BUILTIN ##
SRC		+=	$(BLTINDIR)/builds.c			\
			$(BLTINDIR)/cd.c			\
			$(BLTINDIR)/echo.c

## UTILS ##
SRC		+=	$(UTILSDIR)/utils.c			\
			$(UTILSDIR)/utils2.c			\
			$(UTILSDIR)/get_next_line.c		\
			$(UTILSDIR)/str_to_wordtab.c		\
			$(UTILSDIR)/my_getnbr.c			\
			$(UTILSDIR)/sighandler.c		\
			$(UTILSDIR)/modular_var.c		\
			$(UTILSDIR)/pipe.c			\
			$(UTILSDIR)/free.c			\
			$(UTILSDIR)/pars_env.c

## PRINTF ##
SRC             +=      $(PRTFDIR)/my_disp_unprintable.c        \
                        $(PRTFDIR)/my_printf.c                  \
                        $(PRTFDIR)/my_printf2.c                 \
                        $(PRTFDIR)/my_printf3.c                 \
                        $(PRTFDIR)/my_put_nbr.c                 \
                        $(PRTFDIR)/my_put_u_nbr_base.c          \
                        $(PRTFDIR)/my_put_unbr.c                \
                        $(PRTFDIR)/my_putchar.c                 \
                        $(PRTFDIR)/my_putnbr_base.c             \
                        $(PRTFDIR)/my_putnbr_base_add.c         \
                        $(PRTFDIR)/my_putstr.c                  \
                        $(PRTFDIR)/my_put_fnbr.c

## SPRINTF ##
SRC             +=      $(SPRTFDIR)/my_disp_unprintable.c       \
                        $(SPRTFDIR)/my_sprintf.c                \
                        $(SPRTFDIR)/my_sprintf2.c               \
                        $(SPRTFDIR)/my_sprintf3.c               \
                        $(SPRTFDIR)/my_put_nbr.c                \
                        $(SPRTFDIR)/my_put_u_nbr_base.c         \
                        $(SPRTFDIR)/my_put_unbr.c               \
                        $(SPRTFDIR)/my_putnbr_base.c            \
                        $(SPRTFDIR)/my_putnbr_base_add.c        \
                        $(SPRTFDIR)/my_put_fnbr.c               \
                        $(SPRTFDIR)/my_strcat.c


OBJ             =       $(SRC:.c=.o)

all:                    title $(NAME)

title           :
			@$(ECHO) $(GREEN)Raytracer$(TEAL)2$(DEFAULT)

$(NAME)         :	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) &&   \
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) || \
			$(ECHO) $(RED) "[XX]" $(TEAL) $(NAME) $(DEFAULT)

.c.o            :
			@$(CC) $(CFLAGS) -c $< -o $@ && \
			$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
			$(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)

clean           :
			@$(RM) $(OBJ)

fclean          :	clean
			@$(RM) $(NAME)

re              :	fclean all

.PHONY          :	all clean fclean re
