/*
** pipe.c for minishell in /Users/leandr_g/Documents/Shared folder/PSU_2015_minishell2/src/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Tue Apr 12 16:51:52 2016 Gaëtan Léandre
** Last update Tue Apr 12 18:35:52 2016 Gaëtan Léandre
*/

#include	"main.h"

int		last_pipe(char *cmd, int *pip, t_dlist *dlist)
{
  int		pid;

  pid = fork();
  if (pid == 0)
    {
      dup2(pip[0], 0);
      close(pip[0]);
      close(pip[1]);
      make_command(cmd, dlist);
      exit(0);
    }
  else if (pid == -1)
    return (-1);
  close(pip[0]);
  close(pip[1]);
  return (0);
}

int		mid_pipe(char *cmd, int *pip, t_dlist *dlist, int *prev)
{
  int		pid;

  if (pipe(pip) != 0)
    return (-1);
  pid = fork();
  if (pid == 0)
    {
      dup2(*prev, 0);
      dup2(pip[1], 1);
      close(*prev);
      close(pip[1]);
      make_command(cmd, dlist);
      exit(0);
    }
  else if (pid == -1)
    return (-1);
  close(*prev);
  close(pip[1]);
  *prev = pip[0];
  return (0);
}

int		first_pipe(char *cmd, int *pip, t_dlist *dlist, int *prev)
{
  int		pid;

  if (pipe(pip) != 0)
    return (-1);
  pid = fork();
  if (pid == 0)
    {
      dup2(pip[1], 1);
      close(pip[1]);
      close(pip[0]);
      make_command(cmd, dlist);
      exit(0);
    }
  else if (pid == -1)
    return (-1);
  close(pip[1]);
  *prev = pip[0];
  return (0);
}

void			exec_pipe(t_dlist *dlist, char **pipe, int size)
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
      first_pipe(pipe[0], pip, dlist, &prev);
      i = 1;
      while (i < size - 1)
	mid_pipe(pipe[i++], pip, dlist, &prev);
      last_pipe(pipe[i], pip, dlist);
      i = 0;
      while (i < size)
	{
	  wait(NULL);
	  i++;
	}
    }
}

void			make_pipe(char *cmd, t_dlist *dlist)
{
  char			**pipe;
  int			size;

  pipe = str_to_wordtable(cmd, "|");
  size = 0;
  while (pipe[size])
    size++;
  if (size == 1)
    make_command(pipe[0], dlist);
  else
    exec_pipe(dlist, pipe, size);
  free_tables(pipe);
}
