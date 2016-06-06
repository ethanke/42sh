/*
** pipe.c for minishell in /Users/leandr_g/Documents/Shared folder/PSU_2015_minishell2/src/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Tue Apr 12 16:51:52 2016 Gaëtan Léandre
** Last update Mon Jun  6 07:05:38 2016 Gaëtan Léandre
*/

#include	"main.h"

int		last_pipe(char **cmd, int *pip, t_dlist *dlist)
{
  int		pid;
  int		tmp;

  pid = fork();
  if (pid == 0)
    {
      dup2(pip[0], 0);
      close(pip[0]);
      close(pip[1]);
      tmp = exec_redir(cmd, dlist);
      exit(tmp);
    }
  else if (pid == -1)
    return (-1);
  close(pip[0]);
  close(pip[1]);
  return (0);
}

int		mid_pipe(char **cmd, int *pip, t_dlist *dlist, int *prev)
{
  int		pid;
  int		tmp;

  if (pipe(pip) != 0)
    return (-1);
  pid = fork();
  if (pid == 0)
    {
      dup2(*prev, 0);
      dup2(pip[1], 1);
      close(*prev);
      close(pip[1]);
      tmp = exec_redir(cmd, dlist);
      exit(tmp);
    }
  else if (pid == -1)
    return (-1);
  close(*prev);
  close(pip[1]);
  *prev = pip[0];
  return (0);
}

int		first_pipe(char **cmd, int *pip, t_dlist *dlist, int *prev)
{
  int		pid;
  int		tmp;

  if (pipe(pip) != 0)
    return (-1);
  pid = fork();
  if (pid == 0)
    {
      dup2(pip[1], 1);
      close(pip[1]);
      close(pip[0]);
      tmp = exec_redir(cmd, dlist);
      exit(tmp);
    }
  else if (pid == -1)
    return (-1);
  close(pip[1]);
  *prev = pip[0];
  return (0);
}

int			exec_pipe(t_dlist *dlist, t_cmd *cmd, int size)
{
  int			i;
  int			*pip;
  int			prev;

  if (size < 2)
    write(2, "Invalide pipe\n", 15);
  else if ((pip = malloc(sizeof(int) * 2)) == NULL)
    write(2, "Error malloc sound\n", 20);
  else
    {
      first_pipe(cmd->cmd, pip, dlist, &prev);
      i = 1;
      cmd = cmd->next;
      while (cmd && cmd->token == PI)
	{
	  mid_pipe(cmd->cmd, pip, dlist, &prev);
	  cmd = cmd->next;
	}
      last_pipe(cmd->cmd, pip, dlist);
      i = 0;
      while (i < size)
	{
	  wait(&prev);
	  i++;
	}
      return (prev);
    }
  return (0);
}

int			make_pipe(t_cmd *cmd, t_dlist *dlist)
{
  t_cmd			*tmp;
  int			size;

  size = 1;
  tmp = cmd;
  while (tmp && tmp->token == PI)
    {
      tmp = tmp->next;
      size++;
    }
    size++;
  return (exec_pipe(dlist, cmd, size));
}
