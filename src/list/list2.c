/*
** list2.c for minishell in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Sun Jan 24 21:31:45 2016 Gaëtan Léandre
** Last update Thu May 26 03:39:00 2016 Gaëtan Léandre
*/

#include "list.h"

void			remove_list(t_dlist *dlist)
{
  t_list		*next;

  free_tabs(dlist->env);
  free_tabs(dlist->path);
  while (dlist->start != NULL)
    {
      next = pop_list_start(dlist);
      free(next->name);
      free(next->params);
      free(next);
    }
  free(dlist);
}
