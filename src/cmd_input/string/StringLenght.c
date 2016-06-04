/*
** StringLenght.c for  in /home/sousa_v/perso/prompt_input/src/string/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Jun  4 05:04:34 2016 Victor Sousa
** Last update Sat Jun  4 05:45:20 2016 Victor Sousa
*/

#include	"my_string.h"

int		StringLenght(String string)
{
  int		i;
  t_char	*c;

  i = 0;
  c = string->data;
  while (c != NULL)
    {
      i++;
      c = c->next;
    }
  return (i);
}
