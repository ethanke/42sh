/*
** deleteCharAt.c for  in /home/sousa_v/perso/prompt_input/src/string/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Jun  4 06:16:44 2016 Victor Sousa
** Last update Mon Jun  6 01:03:55 2016 Victor Sousa
*/

#include	"my_string.h"

void		deleteCharAt(String string, int pos)
{
  int		ite;
  t_char	*c;
  t_char	*tmp;

  ite = 0;
  if (pos > StringLenght(string))
    return;
  c = string->data;
  while (c != NULL && ite < pos - 1)
    {
      ite++;
      if (ite < pos - 1)
	c = c->next;
    }
  if (c != NULL && c->next != NULL)
    {
      tmp = c->next;
      c->next = tmp->next;
      free(tmp);
    }
  else if (c != NULL && c->next == NULL)
    {
      string->data = NULL;
      free(c);
    }
}
