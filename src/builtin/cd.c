/*
** cd.c for 42sh in /Users/leandr_g/Documents/Shared folder/42SH/src/builtin/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Thu May 26 03:05:28 2016 Gaëtan Léandre
** Last update Mon Jun  6 15:17:34 2016 Gaëtan Léandre
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
    return (1);
  if ((home = find_with_name(dlist, "PWD")) != NULL)
    my_setenv(dlist, "OLDPWD", home);
  my_setenv(dlist, "PWD", pwd);
  return (0);
}

int			my_cd(t_dlist *dlist, char *command)
{
  int			i;
  char			*home;
  char			*new;

  i = 0;
  while (command && command[i] && command[i] == ' ')
    i++;
  if ((!command || command[i] == '~')
      && (home = find_with_name(dlist, "HOME")) != NULL)
    {
      while (command && command[++i] && command[i] == '/');
      new = (command) ? my_strcat_no_free(home, &command[i]) :
	  my_strcat_no_free(home, "");
    }
  else if (command && my_strcmp(command, "-") == 1
	   && (home = find_with_name(dlist, "OLDPWD")) != NULL)
    new = my_strcat_no_free_b("", home);
  else if (command)
    new = my_strcat_no_free_b("", &command[i]);
  if (home == NULL || new == NULL)
    return (1);
  if (chdir(new) == -1)
    my_printf(2, "bash: cd: %s: No such file or directory\n", command);
  else
    return (change_pwd(dlist));
  return (1);
}
