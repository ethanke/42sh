/*
** term_init.c for  in /home/sousa_v/perso/prompt_input/src/termcap/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Jun  4 03:54:21 2016 Victor Sousa
** Last update Mon Jun  6 14:55:22 2016 Victor Sousa
*/

#include	"prompt.h"

char		*my_tgetstr(char *cap)
{
  char		*s;

  if ((s = tgetstr(cap, NULL)) == NULL)
    {
      dprintf(2, "Error load capacity : %s\n", cap);
      return (NULL);
    }
  return (s);
}

int		init_capacity_termcap(t_termcap *termcap)
{
  if ((termcap->str_cl = my_tgetstr("cl")) == NULL ||
      (termcap->str_do = my_tgetstr("do")) == NULL ||
      (termcap->str_up = my_tgetstr("up")) == NULL ||
      (termcap->str_le = my_tgetstr("le")) == NULL ||
      (termcap->str_ce = my_tgetstr("ce")) == NULL ||
      (termcap->str_cd = my_tgetstr("cd")) == NULL ||
      (termcap->str_ri = my_tgetstr("nd")) == NULL)
    return (-1);
  return (0);
}
