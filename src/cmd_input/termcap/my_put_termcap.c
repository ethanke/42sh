/*
** my_put_termcap.c for  in /home/sousa_v/perso/prompt_input/src/misc/termcap.c/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Jun  4 03:46:21 2016 Victor Sousa
** Last update Sat Jun  4 03:46:35 2016 Victor Sousa
*/

#include	"prompt.h"

int		my_put_termcap(int flag, char *capacity)
{
  static int	fd = -1;
  int		indice;

  if (flag == CLOSE_TTY)
    {
      if (close(fd) == -1)
	perror("close");
      return (-1);
    }
  if (flag != -1)
    fd = flag;
  if (flag == -1 && fd == -1)
    {
      if ((fd = open("/dev/tty", O_RDWR)) == -1)
	perror("open");
    }
  if (fd != -1 && capacity != NULL)
    {
      indice = -1;
      while (capacity[++indice] != '\0');
      if (write(fd, capacity, indice) == -1)
	perror("write");
    }
  return (fd);
}
