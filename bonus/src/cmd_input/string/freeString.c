/*
** freeString.c for  in /home/sousa_v/perso/my_string/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu Jun  2 18:41:34 2016 Victor Sousa
** Last update Thu Jun  2 19:16:53 2016 Victor Sousa
*/

#include	"my_string.h"

void		freeString(String string)
{
  t_char		*tmp;
  t_char                *tmp_next;

  tmp = string->data;
  while (tmp != NULL)
    {
      tmp_next = tmp->next;
      free(tmp);
      tmp = tmp_next;
    }
  free(string);
}
