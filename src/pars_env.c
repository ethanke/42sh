/*
** pars_env.c for minishell in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Sun Jan 24 16:49:20 2016 Gaëtan Léandre
** Last update Sat Apr  9 04:11:53 2016 Gaëtan Léandre
*/

#include 		"minishell.h"

char			*get_name(char *str)
{
  char			*name;
  int			i;
  int			j;

  i = 0;
  j = 0;
  while (str[i] != '=' && str[i])
    {
      i++;
      if (str[i] == '\0')
	return (NULL);
    }
  if ((name = malloc((i + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (j != i)
    {
      name[j] = str[j];
      j++;
    }
  name[j] = '\0';
  return (name);
}

char			*get_params(char *str)
{
  char			*params;
  int			i;
  int			j;
  int			k;

  i = 0;
  j = 0;
  k = 0;
  while (str[i] != '=')
    i++;
  i++;
  while (str[i + j] != '\0')
    j++;
  if ((params = malloc((j + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (k != j)
    {
      params[k] = str[i + k];
      k++;
    }
  params[k] = '\0';
  return (params);
}

char			*compil_env(t_list *list, t_dlist *dlist, int i)
{
  char			*str;
  int			j;

  j = my_strlen(list->name) + my_strlen(list->params) + 2;
  if ((str = malloc(j * sizeof(char))) == NULL)
    exit(EXIT_FAILURE);
  while (i < my_strlen(list->name))
    {
      str[i] = list->name[i];
      i++;
    }
  str[i++] = '=';
  j = 0;
  while (j < my_strlen(list->params))
    {
      str[i] = list->params[j];
      i++;
      j++;
    }
  str[i] = '\0';
  if (my_strcmp("PATH", list->name) == 1)
    dlist->path = str_to_wordtab(list->params, ":");
  else if (my_strcmp("PWD", list->name) == 1)
    dlist->pwd = list->params;
  return (str);
}

void			dlist_to_char(t_dlist *dlist)
{
  t_list		*list;
  int			i;

  i = 0;
  list = dlist->start;
  if ((dlist->env = malloc((dlist->size + 1) * sizeof(char *))) == NULL)
    exit(EXIT_FAILURE);
  dlist->path = NULL;
  while (list != NULL)
    {
      dlist->env[i] = compil_env(list, dlist, 0);
      i++;
      list = list->next;
    }
  dlist->env[i] = NULL;
}

int			get_env(char **env, t_dlist *dlist)
{
  t_list		*list;
  char			*name;
  char			*params;
  int			i;

  i = 0;
  dlist->pwd = NULL;
  dlist->path = NULL;
  while (env[i] != NULL)
    {
      if ((name = get_name(env[i])) == NULL)
	return (-1);
      else if ((params = get_params(env[i])) == NULL)
	return (-1);
      else if ((list = create_list(name, params)) == NULL)
	return (-1);
      insert_list_end(list, dlist);
      i++;
    }
  dlist_to_char(dlist);
  return (0);
}
