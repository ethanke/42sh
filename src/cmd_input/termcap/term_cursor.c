/*
** term_cursor.c for  in /home/sousa_v/perso/prompt_input/src/termcap/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Jun  4 04:47:19 2016 Victor Sousa
** Last update Sat Jun  4 04:47:35 2016 Victor Sousa
*/

#include	"prompt.h"

int		curseur(int x, int y)
{
  char		*s;
  char		*curser;

  if ((s = tgetstr("cm", NULL)) == NULL)
    {
      perror("tgetstr");
      return (EXIT_FAILURE);
    }
  if ((curser = tgoto(s, x, y)) == NULL)
    return (EXIT_FAILURE);
  my_put_termcap(-1, curser);
  return (EXIT_SUCCESS);
}
