/*
** list.c for list in /home/leandr_g/perso/list
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Tue Nov 17 11:33:39 2015 Gaëtan Léandre
** Last update Sat Apr  9 04:10:08 2016 Gaëtan Léandre
*/

#include 		"list.h"

t_dlist			*create_dlist()
{
  t_dlist		*list;

  if ((list = malloc(sizeof(t_dlist))) == NULL)
    return (NULL);
  list->size = 0;
  list->start = NULL;
  list->end = NULL;
  return (list);
}

t_list			*create_list(char *name, char *params)
{
  t_list		*list;

  if ((list = malloc(sizeof(t_list))) == NULL)
    return (NULL);
  list->name = name;
  list->params = params;
  list->prev = NULL;
  list->next = NULL;
  return (list);
}

void			insert_list_end(t_list *list, t_dlist *dlist)
{
  list->prev = dlist->end;
  if (dlist->end != NULL)
    dlist->end->next = list;
  dlist->end = list;
  list->next = NULL;
  if (dlist->start == NULL)
    dlist->start = list;
  dlist->size = dlist->size + 1;
}

t_list			*pop_list_start(t_dlist *dlist)
{
  t_list		*result;

  if (dlist->size == 0)
    return (NULL);
  result = dlist->start;
  if (dlist->size == 1)
    dlist->end = NULL;
  else
    result->next->prev = NULL;
  dlist->start = result->next;
  dlist->size = dlist->size - 1;
  return (result);
}

void			pop_list(t_list *list, t_dlist *dlist)
{
  if (dlist->size == 1)
    {
      dlist->start = NULL;
      dlist->end = NULL;
    }
  if (list->next != NULL)
    list->next->prev = list->prev;
  if (list->prev != NULL)
    list->prev->next = list->next;
  if (dlist->start == list)
    dlist->start = list->next;
  if (dlist->end == list)
    dlist->end = list->prev;
  dlist->size = dlist->size - 1;
  free(list);
}
