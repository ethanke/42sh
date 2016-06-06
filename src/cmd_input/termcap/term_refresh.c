/*
** term_refresh.c for  in /home/sousa_v/perso/prompt_input/src/termcap/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Jun  4 04:48:20 2016 Victor Sousa
** Last update Mon Jun  6 17:27:14 2016 Victor Sousa
*/

#include	"prompt.h"
#include	"main.h"

void		term_refresh(t_edit_line *line)
{
  curseur(0, line->start_pos_y);
  disp_pwd(modular_pwd(0, NULL));
  dprintf(line->fd_tty, line->termcap.str_cd);
}
