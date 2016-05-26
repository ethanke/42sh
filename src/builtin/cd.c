/*
** cd.c for 42sh in /Users/leandr_g/Documents/Shared folder/42SH/src/builtin/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu May 26 03:05:28 2016 Gaëtan Léandre
** Last update Thu May 26 04:18:09 2016 Gaëtan Léandre
*/

#include 		"main.h"

char			*find_with_name(t_dlist *dlist, char *name)
{
  t_list		*list;

  list = dlist->start;
  while (list != NULL)
    {
      if (my_strcmp(name, list->name) == 1)
	return (list->params);
      list = list->next;
    }
  return (NULL);
}

void			my_cd(t_dlist *dlist, char *command)
{
  int			i;
  char			*home;
  char			*new;

  i = 0;
  while (command[i] && command[i] == ' ')
    i++;
  if (command[i] == '~' && (home = find_with_name(dlist, "HOME")) != NULL)
    {
      while (command[++i] && command[i] == '/');
      if ((new = my_strcat_no_free(home, "/")) == NULL)
	return;
      new = my_strcat_first(new, &command[i]);
    }
  else
    new = my_strcat_no_free("", &command[i]);
  if (new == NULL)
    return;
  chdir(new);
  free(new);
}
