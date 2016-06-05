/*
** builds.c for minishell in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Sun Jan 24 16:48:02 2016 Gaëtan Léandre
** Last update Sun Jun  5 01:33:19 2016 Gaëtan Léandre
*/

#include 		"main.h"

int			my_env(t_dlist *dlist)
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
  return (1);
}

int			my_setenv(t_dlist *dlist, char *name, char *params)
{
  t_list		*list;

  list = dlist->start;
  while (list != NULL)
    {
      if (my_strcmp(list->name, name) == 1)
	{
	  free(list->params);
	  list->params = my_strdup(params);
	  free_env(dlist);
	  dlist_to_char(dlist);
	  return (1);
	}
      list = list->next;
    }
  if ((list = create_list(my_strdup(name), my_strdup(params))) == NULL)
    exit(EXIT_FAILURE);
  insert_list_end(list, dlist);
  free_env(dlist);
  free_tables(dlist->path);
  dlist_to_char(dlist);
  return (1);
}

int			my_unsetenv(t_dlist *dlist, char *name)
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
	  free_tables(dlist->path);
	  dlist_to_char(dlist);
	  return (1);
	}
      list = list->next;
    }
  return (0);
}

int			check_cmd(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      i++;
    }
  return (0);
}

int			my_exit(t_dlist *dlist, char **cmd)
{
  int	last;

  if (cmd[1] == NULL)
    last = 0;
  else if (cmd[2] != NULL || check_cmd(cmd[1]) == -1)
    {
      my_putstr("error : Expression syntax\n");
      return (0);
    }
  else
    last = my_getnbr(cmd[1]);
  free_tables(cmd);
  remove_list(dlist);
  my_putstr("exit\n");
  exit(last);
}
