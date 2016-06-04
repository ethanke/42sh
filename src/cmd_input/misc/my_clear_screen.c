/*
** my_clear_screen.c for  in /home/sousa_v/perso/prompt_input/src/misc/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Jun  4 03:02:21 2016 Victor Sousa
** Last update Sat Jun  4 05:16:29 2016 Victor Sousa
*/

#include	"prompt.h"

int		my_clear_screen(t_edit_line *line)
{
  char		*s;

  if ((s = tgetstr("cl", NULL)) == NULL)
    {
      perror("tgetstr");
      return (EXIT_FAILURE);
    }
  my_put_termcap(-1, s);
  line->start_pos_x = 0;
  line->start_pos_y = 0;
  return (EXIT_SUCCESS);
}
