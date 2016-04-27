/*
** utils2.c for minishell in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Sun Jan 24 19:19:55 2016 Gaëtan Léandre
** Last update Sat Apr  9 04:04:14 2016 Gaëtan Léandre
*/

#include "minishell.h"

char	*my_strcpy(char *str)
{
  char	*cpy;
  int	i;

  if (str == NULL)
    {
      if ((cpy = malloc(1)) == NULL)
	exit(EXIT_FAILURE);
      cpy[0] = '\0';
      return (cpy);
    }
  if ((cpy = malloc((my_strlen(str) + 1))) == NULL)
    exit(EXIT_FAILURE);
  i = 0;
  while (str[i])
    {
      cpy[i] = str[i];
      i++;
    }
  cpy[i] = '\0';
  return (cpy);
}

void	disp_pwd(char *pwd)
{
  if (pwd != NULL)
    my_putstr(pwd);
  my_putchar('>');
}

void	find_name(t_dlist *dlist, char **cmd)
{
  DIR		*rep;
  int		i;
  struct dirent	*file;

  i = 0;
  while (dlist->path && dlist->path[i] != NULL)
    {
      if ((rep = opendir(dlist->path[i])) != NULL)
	{
	  while ((file = readdir(rep)) != NULL)
	    {
	      if (my_strcmp(file->d_name, cmd[0]) == 1)
		{
		  cmd[0] = my_strcat(dlist->path[i], cmd[0]);
		  return;
		}
	    }
	  closedir(rep);
	}
      i++;
    }
}
