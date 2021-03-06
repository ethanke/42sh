/*
** main.c for minishell1 in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Sat Jan 23 02:27:31 2016 Gaëtan Léandre
** Last update Mon Jun  6 23:34:05 2016 victor sousa
*/

#include 		"main.h"

char			*reverse_inib(char *str)
{
  int			i;
  int			j;
  char			flag;
  char			*new;

  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (str);
  j = ((i = -1) + (flag = 0)) * 0;
  while (str[++i])
    {
      if (str[i] == '\"')
	{
	  if (flag == 0)
	    flag = 1;
	  else
	    flag = 0;
	}
      else if (flag)
	new[j++] = - str[i];
      else
	new[j++] = str[i];
    }
  new[j] = '\0';
  free(str);
  return (new);
}

int			main(int ac, char **av, char **env)
{
  t_dlist		*dlist;
  char			*cmd;
  int			result;

  (void)ac;
  (void)av;
  result = 0;
  if ((dlist = create_dlist()) == NULL)
    return (-1);
  get_env(env, dlist);
  modular_pwd(1, dlist->pwd);
  disp_pwd(modular_pwd(0, NULL));
  signal(SIGINT, sighandler);
  while ((cmd = get_next_line(0)) != NULL)
    {
      cmd = reverse_inib(cmd);
      result = send_cmd(parsing(cmd, dlist->path), dlist);
      disp_pwd(modular_pwd(0, NULL));
      free(cmd);
    }
  my_putchar('\n');
  return ((isatty(0) != 1) ? result : 0);
}
