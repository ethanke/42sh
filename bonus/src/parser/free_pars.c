/*
** free_pars.c for parser in /Users/leandr_g/Documents/Shared folder/42SH/src/parser/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Jun  5 01:19:35 2016 Gaëtan Léandre
** Last update Sun Jun  5 01:52:33 2016 Gaëtan Léandre
*/

#include		"main.h"

void          	clear_list(t_pile *list)
{
 t_pile         *tmp;
 t_pile         *tmpnext;

 tmp = list;
 while (tmp != NULL)
   {
     tmpnext = tmp->next;
     free(tmp);
     tmp = tmpnext;
   }
}

int			free_for_all(char **table)
{
  int			i;

  i = -1;
  while (table[++i])
    free(table[i]);
  free(table);
  return (0);
}
