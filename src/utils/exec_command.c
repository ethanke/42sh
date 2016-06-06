/*
** exec_command.c for 42 in /Users/leandr_g/Documents/Shared folder/42SH/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Jun  6 21:26:45 2016 Gaëtan Léandre
** Last update Mon Jun  6 21:27:21 2016 Gaëtan Léandre
*/

#include 		"main.h"

int			launch_setenv(t_dlist *dlist, char **cmd)
{
  if (cmd[1] == NULL)
    my_env(dlist);
  else if (cmd[2] == NULL)
    my_setenv(dlist, cmd[1], NULL);
  else if (cmd[3] == NULL)
    my_setenv(dlist, cmd[1], cmd[2]);
  else
    my_putstr("too many arguments\n");
  return (0);
}

int			my_loop_unset(t_dlist *dlist, char **cmd)
{
  int			i;

  i = 1;
  while (cmd[i])
    my_unsetenv(dlist, cmd[i++]);
  return (0);
}

int			test_build(t_dlist *dlist, char **cmd, int *cont)
{
  if (my_strcmp(cmd[0], "exit") == 1 || my_strcmp(cmd[0], "quit") == 1)
    return (my_exit(dlist, cmd));
  else if (my_strcmp(cmd[0], "env") == 1 && cmd[1] == NULL)
    return (my_env(dlist));
  else if (my_strcmp(cmd[0], "setenv") == 1)
    return (launch_setenv(dlist, cmd));
  if (my_prompt_strcmp(cmd[0], "history") == 1)
    return (history_buildin());
  else if (my_strcmp(cmd[0], "unsetenv") == 1)
    {
      if (cmd[1] == NULL)
	my_putstr("no arguments\n");
      else
	return (my_loop_unset(dlist, cmd));
      return (1);
    }
  else if (my_strcmp(cmd[0], "cd") == 1)
    return (my_cd(dlist, cmd[1]));
  *cont = 1;
  return (0);
}

int			launch(t_dlist *dlist, char **cmd)
{
  int			pid;
  int			pid_stat;

  if ((pid = fork()) == 0)
    {
      if (execve(cmd[0], cmd, dlist->env) == -1)
	{
	  my_printf(2, "%s: Command not found.\n", cmd[0]);
	  exit(1);
	}
    }
  else
    {
      waitpid(pid, &pid_stat, 0);
      if (WIFEXITED(pid_stat))
	return (WEXITSTATUS(pid_stat));
      else if (WIFSIGNALED(pid_stat))
	disp_msg(WTERMSIG(pid_stat));
    }
  return (0);
}

int			make_command(char **cmd, t_dlist *dlist)
{
  int			tmp;
  int			cont;

  cont = 0;
  find_name(dlist, cmd);
  tmp = test_build(dlist, cmd, &cont);
  if (cont == 1)
    tmp = launch(dlist, cmd);
  return (tmp);
}
