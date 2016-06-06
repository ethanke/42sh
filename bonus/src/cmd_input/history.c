/*
** history.c for  in /home/sousa_v/rendu/psu/42_temp/src/cmd_input/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Jun  6 02:54:25 2016 Victor Sousa
** Last update Mon Jun  6 03:33:59 2016 Victor Sousa
*/

#include	"prompt.h"

t_history			*add_to_history(t_history *list, int id, char *cmd)
{
  t_history		*new;
  t_history		*tmp;

  if ((new = malloc(sizeof(t_history))) == NULL)
    return (list);
  new->id = id;
  new->cmd = cmd;
  new->next = NULL;
  tmp = list;
  while (tmp && tmp->next)
    tmp = tmp->next;
  new->prev = tmp;
  if (tmp != NULL)
    tmp->next = new;
  else
    return (new);
  return (list);
}
