/*
** cd.c for 42sh in /Users/leandr_g/Documents/Shared folder/42SH/src/builtin/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu May 26 03:05:28 2016 Gaëtan Léandre
** Last update Sun Jun  5 01:34:26 2016 Gaëtan Léandre
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

int			change_pwd(t_dlist *dlist)
{
  char			pwd[1024];
  char			*home;

  if (getcwd(pwd, 1024) == NULL)
    return (0);
  if ((home = find_with_name(dlist, "PWD")) != NULL)
    my_setenv(dlist, "OLDPWD", home);
  my_setenv(dlist, "PWD", pwd);
  return (1);
}

int			my_cd(t_dlist *dlist, char *command)
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
      new = my_strcat_no_free(home, &command[i]);
    }
  else if (my_strcmp(command, "-") == 1
	   && (home = find_with_name(dlist, "OLDPWD")) != NULL)
    new = my_strcat_no_free_b("", home);
  else
    new = my_strcat_no_free_b("", &command[i]);
  if (new == NULL)
    return (0);
  if (chdir(new) == -1)
    my_printf(2, "bash: cd: %s: No such file or directory\n", command);
  else
    return (change_pwd(dlist));
  free(new);
  return (0);
}
