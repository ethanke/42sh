/*
** main.c for minishell1 in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Sat Jan 23 02:27:31 2016 Gaëtan Léandre
** Last update Thu May 26 05:14:00 2016 Gaëtan Léandre
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

int			test_build(t_dlist *dlist, char **cmd)
{
  int			i;

  i = 1;
  if (my_strcmp(cmd[0], "exit") == 1 || my_strcmp(cmd[0], "quit") == 1)
    return (my_exit(dlist, cmd));
  else if (my_strcmp(cmd[0], "env") == 1 && cmd[1] == NULL)
    {
      my_env(dlist);
      return (0);
    }
  else if (my_strcmp(cmd[0], "setenv") == 1)
    return (launch_setenv(dlist, cmd));
  else if (my_strcmp(cmd[0], "unsetenv") == 1)
    {
      if (cmd[1] == NULL)
	my_putstr("no arguments\n");
      else
	{
	  while (cmd[i])
	    my_unsetenv(dlist, cmd[i++]);
	}
      return (0);
    }
  else if (my_strcmp(cmd[0], "cd") == 1)
    return (my_cd(dlist, cmd[1]));
  return (1);
}

void			launch(t_dlist *dlist, char **cmd)
{
  int			pid;
  int			pid_stat;

  if ((pid = fork()) == 0)
    {
      if (execve(cmd[0], cmd, dlist->env) == -1)
	{
	  write(2, "Command-not-found\n", 19);
	  exit(1);
	}
    }
  else
    {
      waitpid(pid, &pid_stat, 0);
      if (WIFEXITED(pid_stat))
	pid_stat = WEXITSTATUS(pid_stat);
      else if (WIFSIGNALED(pid_stat) && (pid_stat = WTERMSIG(pid_stat)) == 11)
	write(2, "Segmentation fault\n", 20);
    }
}

void			make_command(char *cmd, t_dlist *dlist)
{
  char			**test;

  test = str_to_wordtab(cmd, " \t");
  if (test[0] == NULL)
    return;
  find_name(dlist, test);
  if (test_build(dlist, test) == 1)
    launch(dlist, test);
  free_tabs(test);
}

int			main(int ac, char **av, char **env)
{
  char			**test;
  t_dlist		*dlist;
  char			*cmd;
  int			i;

  (void)ac;
  (void)av;
  if ((dlist = create_dlist()) == NULL)
    return (-1);
  get_env(env, dlist);
  disp_pwd(modular_pwd(0, NULL));
  signal(SIGINT, sighandler);
  while ((cmd = get_next_line(0)) != NULL)
    {
      i = -1;
      test = str_to_wordtab(cmd, ";");
      while (test && test[++i])
	make_pipe(test[i], dlist);
      free_tabs(test);
      disp_pwd(modular_pwd(0, NULL));
    }
  my_putchar('\n');
  return (0);
}
