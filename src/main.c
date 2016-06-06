/*
** main.c for minishell1 in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Sat Jan 23 02:27:31 2016 Gaëtan Léandre
** Last update Mon Jun  6 06:55:09 2016 Ethan Kerdelhue
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

int			test_build(t_dlist *dlist, char **cmd, int *cont)
{
  int			i;

  i = 1;
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
	{
	  while (cmd[i])
	    my_unsetenv(dlist, cmd[i++]);
	  return (1);
	}
      return (0);
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
	  my_printf(2, "%s\n", strerror(errno));
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
  tmp = (tmp != 0) ? 1 : 0;
  return (tmp);
}

void			reverse_inib(char *str)
{
  int			i;
  char			flag;

  flag = 0;
  i = 0;
  while (str[i])
    {
      if (str[i] == '\"')
	{
	  if (flag == 0)
	    flag = 1;
	  else
	    flag = 0;
	}
      if (flag)
	str[i] = - str[i];
      i++;
    }
}

int			main(int ac, char **av, char **env)
{
  t_dlist		*dlist;
  char			*cmd;
  t_edit_line		line;

  (void)ac;
  (void)av;
  modular_history(1, NULL);
  if ((line.fd_tty = open("/dev/tty", O_RDWR)) == -1)
    return (-1);
  my_put_termcap(line.fd_tty, NULL);
  if (reset_save_mode(0, line.fd_tty) == EXIT_FAILURE)
    {
      dprintf(2, "Error SAVE termcap\n");
      return (-1);
    }
  if (mode_raw(line.fd_tty) == EXIT_FAILURE)
    {
      dprintf(2, "Error mod_raw termcap\n");
      return (-1);
    }
  if ((dlist = create_dlist()) == NULL)
    return (-1);
  get_env(env, dlist);
  modular_pwd(1, dlist->pwd);
  disp_pwd(modular_pwd(0, NULL));
  signal(SIGINT, sighandler);
  while ((cmd = get_prompt_input(&line, env)) != NULL)
    {
      reverse_inib(cmd);
      send_cmd(parsing(cmd, dlist->path), dlist);
      disp_pwd(modular_pwd(0, NULL));
      free(cmd);
    }
  my_putchar('\n');
  return (0);
}
