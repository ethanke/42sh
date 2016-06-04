/*
** free.c for minishell in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Sun Jan 24 16:43:19 2016 Gaëtan Léandre
** Last update Sat Apr  9 04:09:00 2016 Gaëtan Léandre
*/

#include 		"main.h"

void			free_tables(char **str)
{
  int			i;

  i = 0;
  while (str && str[i] != NULL)
    {
      free(str[i]);
      i++;
    }
  free(str);
}

void			free_env(t_dlist *dlist)
{
  int			i;

  i = 0;
  while (dlist->env[i] != NULL)
    {
      free(dlist->env[i]);
      i++;
    }
  free(dlist->env);
}
