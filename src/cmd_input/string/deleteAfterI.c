/*
** deleteAfterI.c for  in /home/sousa_v/rendu/psu/42_temp/src/cmd_input/string/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Jun  5 22:28:01 2016 Victor Sousa
** Last update Mon Jun  6 00:31:23 2016 Victor Sousa
*/

#include	"my_string.h"
#include	<stdio.h>

void		deleteAfterI(String string, int pos)
{
  t_char	*cur;
  String	toFree;
  int		ite;

  ite = 0;
  cur = string->data;
  while (cur != NULL && cur->next != NULL && ite < pos - 1)
    {
      cur = cur->next;
      ite++;
    }
  if ((toFree = malloc(sizeof(t_string))) == NULL)
    return;
  if (cur != NULL)
    toFree->data = cur->next;
  else
    toFree->data = cur;
  freeString(toFree);
  if (cur != NULL)
    cur->next = NULL;
}
