/*
** term_refresh.c for  in /home/sousa_v/perso/prompt_input/src/termcap/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Jun  4 04:48:20 2016 Victor Sousa
** Last update Sat Jun  4 05:02:03 2016 Victor Sousa
*/

#include	"prompt.h"

void		term_refresh(t_edit_line *line)
{
  curseur(line->start_pos_x, line->start_pos_y);
  dprintf(line->fd_tty, line->termcap.str_cd);
}
