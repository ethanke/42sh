##
## Makefile for minishell in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
##
## Made by Gaëtan Léandre
## Login   <leandr_g@epitech.net>
##
## Started on  Sat Jan 23 02:23:24 2016 Gaëtan Léandre
## Last update Mon Jun  6 23:23:50 2016 victor sousa
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
PARSDIR        =       	$(SRCDIR)/parser

INCDIR          =       inc
LIBDIR          =       lib

RM              =       rm -f

CC              =       gcc
CFLAGS		=	-W -Wall -Wextra -Werror		\
			-ansi -pedantic				\
			-I$(INCDIR)				\
			-lncurses

##  MAIN  ##
SRC             =       $(SRCDIR)/main.c

## LIST ##
SRC		+=	$(LISTDIR)/list.c			\
			$(LISTDIR)/list2.c

## BUILTIN ##
SRC		+=	$(BLTINDIR)/builds.c			\
			$(BLTINDIR)/cd.c			\
			$(BLTINDIR)/echo.c			\
			$(BLTINDIR)/history_builtin.c

## UTILS ##
SRC		+=	$(UTILSDIR)/utils.c			\
			$(UTILSDIR)/utils2.c			\
			$(UTILSDIR)/utils3.c			\
			$(UTILSDIR)/get_next_line.c		\
			$(UTILSDIR)/str_to_wordtab.c		\
			$(UTILSDIR)/my_getnbr.c			\
			$(UTILSDIR)/sighandler.c		\
			$(UTILSDIR)/modular_var.c		\
			$(UTILSDIR)/pipe.c			\
			$(UTILSDIR)/free.c			\
			$(UTILSDIR)/pars_env.c			\
			$(UTILSDIR)/redirect.c			\
			$(UTILSDIR)/glob.c			\
			$(UTILSDIR)/disp_msg.c			\
			$(UTILSDIR)/exec_command.c		\
			src/parser/endparsing.c			\
			$(UTILSDIR)/auto_complete.c

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

SRC		+=	$(PARSDIR)/cmd.c			\
			$(PARSDIR)/epur.c			\
			$(PARSDIR)/my_cat.c			\
		   	$(PARSDIR)/utils.c			\
			$(PARSDIR)/free_pars.c			\
			$(PARSDIR)/link_list.c			\
	 		$(PARSDIR)/list_utils.c			\
			$(PARSDIR)/opt.c			\
			$(PARSDIR)/error_case.c			\
			$(PARSDIR)/pars_utils.c			\
			$(PARSDIR)/pars.c			\
			$(PARSDIR)/send_redir.c			\
			$(PARSDIR)/send_redir2.c		\
			$(PARSDIR)/sep.c			\
			$(PARSDIR)/start_pars.c

OBJ             =       $(SRC:.c=.o)

all:                    title $(NAME)

title           :
			@$(ECHO) $(GREEN)42$(TEAL)sh$(DEFAULT)

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
