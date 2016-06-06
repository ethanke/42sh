##
## Makefile for minishell in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
##
## Made by Gaëtan Léandre
## Login   <leandr_g@epitech.net>
##
## Started on  Sat Jan 23 02:23:24 2016 Gaëtan Léandre
## Last update Mon Jun  6 04:32:36 2016 Kerdelhue Ethan
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
			-I$(INCDIR) -ggdb -g3			\
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
			$(UTILSDIR)/get_next_line.c		\
			$(UTILSDIR)/str_to_wordtab.c		\
			$(UTILSDIR)/my_getnbr.c			\
			$(UTILSDIR)/sighandler.c		\
			$(UTILSDIR)/modular_var.c		\
			$(UTILSDIR)/pipe.c			\
			$(UTILSDIR)/free.c			\
			$(UTILSDIR)/pars_env.c			\
			$(UTILSDIR)/redirect.c			\
			$(UTILSDIR)/disp_msg.c

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
			$(PARSDIR)/free_pars.c			\
			$(PARSDIR)/link_list.c			\
			$(PARSDIR)/opt.c			\
			$(PARSDIR)/error_case.c			\
			$(PARSDIR)/pars_utils.c			\
			$(PARSDIR)/pars.c			\
			$(PARSDIR)/send_redir.c			\
			$(PARSDIR)/sep.c			\
			$(PARSDIR)/start_pars.c

## TERMCAP
SRC		+=	src/cmd_input/getPromptInput.c			\
			src/cmd_input/history.c				\
			src/cmd_input/termcap/my_put_termcap.c		\
			src/cmd_input/termcap/term_mode.c		\
			src/cmd_input/termcap/term_init.c		\
			src/cmd_input/termcap/term_cursor.c		\
			src/cmd_input/termcap/term_refresh.c		\
			src/cmd_input/termcap/term_cursor_position.c	\
		      	src/cmd_input/termcap/term_get_size.c

## MISC
SRC		+=	src/cmd_input/misc/xfree.c			\
			src/cmd_input/misc/str.c			\
			src/cmd_input/misc/my_clear_screen.c		\
			src/cmd_input/misc/get_env_var.c

## STRING
SRC		+=	src/cmd_input/string/concatString.c		\
			src/cmd_input/string/formString.c		\
			src/cmd_input/string/freeString.c		\
			src/cmd_input/string/printString.c		\
			src/cmd_input/string/pushChar.c			\
			src/cmd_input/string/deleteCharAt.c		\
			src/cmd_input/string/StringLenght.c		\
			src/cmd_input/string/StringToArray.c		\
			src/cmd_input/string/copyStringFrom.c		\
			src/cmd_input/string/deleteAfterI.c


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
