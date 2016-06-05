/*
** redirect.c for redirect.c in /Users/leandr_g/Documents/Shared folder/42SH/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Jun  5 02:18:19 2016 Gaëtan Léandre
** Last update Sun Jun  5 19:41:21 2016 tanguy lelievre
*/

#include	"main.h"

int		right_redir(char **start, char *end, t_dlist *dlist)
{
  int	fd;
  int	reset;

  if ((reset = dup(1)) == -1)
    return (0);
  if ((fd = open(end, O_WRONLY | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (0);
  if (dup2(fd, 1) == -1 || make_command(start, dlist) == 0 ||
      dup2(reset, 1) == -1)
    return (0);
  close(fd);
  return (1);
}

int		dright_redir(char **start, char *end, t_dlist *dlist)
{
   int		fd;
  char		*buff;
  struct stat	stats;
  int		reset;

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
  if (stat(end, &stats) == -1 ||
      (buff = malloc(stats.st_size + 1)) == NULL ||
      read(fd, buff, stats.st_size) == -1)
    return (0);
  if (dup2(fd, 1) == -1 || make_command(start, dlist) == 0 ||
      dup2(reset, 1) == -1)
    return (0);
  close(fd);
  return (1);
}

int		left_redir(char **start, char *end, t_dlist *dlist)
{
  (void)start;
  (void)end;
  (void)dlist;
  puts("left");
  return (1);
}

int		dleft_redir(char **start, char *end, t_dlist *dlist)
{
  (void)start;
  (void)end;
  (void)dlist;
  puts("dlef");
  return (1);
}
