/*
** builds.c for minishell in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Sun Jan 24 16:48:02 2016 Gaëtan Léandre
** Last update Sat Apr  9 04:08:46 2016 Gaëtan Léandre
*/

#include 		"minishell.h"

void			my_env(t_dlist *dlist)
{
  t_list		*tmp;

  tmp = dlist->start;
  while (tmp != NULL)
    {
      my_putstr(tmp->name);
      my_putchar('=');
      my_putstr(tmp->params);
      my_putchar('\n');
      tmp = tmp->next;
    }
}

void			my_setenv(t_dlist *dlist, char *name, char *params)
{
  t_list		*list;

  list = dlist->start;
  while (list != NULL)
    {
      if (my_strcmp(list->name, name) == 1)
	{
	  free(list->params);
	  list->params = my_strcpy(params);
	  free_env(dlist);
	  dlist_to_char(dlist);
	  return;
	}
      list = list->next;
    }
  if ((list = create_list(my_strcpy(name), my_strcpy(params))) == NULL)
    exit(EXIT_FAILURE);
  insert_list_end(list, dlist);
  free_env(dlist);
  free_tabs(dlist->path);
  dlist_to_char(dlist);
}

void			my_unsetenv(t_dlist *dlist, char *name)
{
  t_list		*list;

  list = dlist->start;
  while (list != NULL)
    {
      if (my_strcmp(list->name, name) == 1)
	{
	  free(list->name);
	  free(list->params);
	  pop_list(list, dlist);
	  free_env(dlist);
	  free_tabs(dlist->path);
	  dlist_to_char(dlist);
	  return;
	}
      list = list->next;
    }
}

void			my_exit(t_dlist *dlist, char **cmd)
{
  int	last;

  if (cmd[1] == NULL)
    last = 0;
  else if (cmd[2] != NULL)
    {
      my_putstr("error : Expression syntax\n");
      return;
    }
  else
    last = my_getnbr(cmd[1]);
  free_tabs(cmd);
  remove_list(dlist);
  my_putstr("exit\n");
  exit(last);
}
