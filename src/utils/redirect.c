/*
** redirect.c for redirect.c in /Users/leandr_g/Documents/Shared folder/42SH/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Jun  5 02:18:19 2016 Gaëtan Léandre
** Last update Mon Jun  6 17:35:30 2016 tanguy lelievre
*/

#include	"main.h"
#include	"prompt.h"

int		right_redir(char **start, char *end, t_dlist *dlist)
{
  int		fd;
  int		reset;
  int		to_ret;

  to_ret = 1;
  if ((reset = dup(1)) == -1)
    return (0);
  else if ((fd = open(end, O_WRONLY | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (0);
  else if (dup2(fd, 1) == -1 || make_command(start, dlist) == 0)
    to_ret = 0;
  dup2(reset, 1);
  close(fd);
  return (to_ret);
}

int		dright_redir(char **start, char *end, t_dlist *dlist)
{
  int		fd;
  char		*buff;
  struct stat	stats;
  int		reset;
  int		to_ret;

  to_ret = 1;
  if ((reset = dup(1)) == -1)
    return (0);
  if (access(end, F_OK) == -1)
    {
      if ((fd = open(end, O_RDWR | O_CREAT | O_TRUNC,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	return (0);
    }
  else if ((fd = open(end, O_RDWR)) == -1)
    return (0);
  if (stat(end, &stats) == -1 || (buff = malloc(stats.st_size + 1)) == NULL ||
      read(fd, buff, stats.st_size) == -1)
    return (0);
  if (dup2(fd, 1) == -1 || make_command(start, dlist) == 0)
    to_ret = 0;
  dup2(reset, 1);
  close(fd);
  return (to_ret);
}

int		left_redir(char **start, char *end, t_dlist *dlist)
{
  int		fd;
  int		reset;
  int		to_ret;

  to_ret = 1;
  if ((reset = dup(0)) == -1)
    return (0);
  if (access(end, F_OK) == -1 || (fd = open(end, O_RDWR)) == -1)
    return (0);
  if (dup2(fd, 0) == -1 || make_command(start, dlist) == 0)
    to_ret = 0;
  dup2(reset, 0);
  close(fd);
  return (to_ret);
}

int		dleft_redir(char **start, char *end, t_dlist *dlist)
{
  int		fd[2];
  char		*str;
  int		diff;
  int		reset;
  t_edit_line	*line;

  line = modular_line(0, NULL);
  diff = 0;
  if (pipe(fd) == -1 || (reset = dup(line->fd_tty)) == -1)
    return (0);
  modular_pwd(1, "");
  while (diff == 0)
    {
      str = get_prompt_input(line, dlist->env);
      if (str && (diff = my_strcmp(str, end)) == 0)
	my_printf(fd[1], "%s\n", str);
    }
  close(fd[1]);
  if (dup2(fd[0], 0) == -1 || make_command(start, dlist) == 0)
    diff = 0;
  close(fd[0]);
  dup2(reset, 0);
  modular_pwd(1, dlist->pwd);
  return (diff);
}
