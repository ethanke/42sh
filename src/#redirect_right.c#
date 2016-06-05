/*
** redirect.c for 42sh in /home/leliev_t/rendu/42sh
** 
** Made by tanguy lelievre
** Login   <leliev_t@epitech.net>
** 
** Started on  Tue May 31 14:22:18 2016 tanguy lelievre
** Last update Sat Jun  4 15:55:30 2016 tanguy lelievre
*/

# include "main.h"

int	redirect_right(/* char **cmd,  */
		       char *name/* , */
		       /*t_dlist *dlist */)
{
  int	fd;
  int	reset;

  if ((reset = dup(1)) == -1)
    return (0);
  if ((fd = open(name, O_WRONLY | O_CREAT | O_TRUNC,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (0);
  if (dup2(fd, 1) == -1 /* || make_command(cmd, dlist) == 0 */ ||
      dup2(reset, 1) == -1)
    return (0);
  close(fd);
  return (1);
}

int		double_redirect_right(/* char ** cmd, */
				      char *name/* , */
				      /* t_dlist *dlist */)
{
  int		fd;
  char		*buff;
  struct stat	stats;
  int		reset;

  if ((reset = dup(1)) == -1)
    return (0);
  if (access(name, F_OK) == -1)
    {
      if ((fd = open(name, O_RDWR | O_CREAT | O_TRUNC,
		     S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
	return (0);
    }
  else if ((fd = open(name, O_RDWR)) == -1)
    return (0);
  if (stat(name, &stats) == -1 ||
      (buff = malloc(stats.st_size + 1)) == NULL ||
      read(fd, buff, stats.st_size) == -1)
    return (0);
  if (dup2(fd, 1) == -1 /* || make_command(cmd, dlist) == 0 */ ||
      dup2(reset, 1) == -1)
    return (0);
  close(fd);
  return (1);
}
