/*
** term_get_size.c for  in /home/sousa_v/perso/prompt_input/src/termcap/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Jun  4 05:53:54 2016 Victor Sousa
** Last update Sat Jun  4 05:54:05 2016 Victor Sousa
*/

#include	"prompt.h"

int			get_termsize_x(void)
{
  struct winsize	ws;
  int			fd;

  fd = my_put_termcap(-1, NULL);
  if (ioctl(fd, TIOCGWINSZ, &ws) == -1)
    {
      perror("ioctl");
      return (1);
    }
  return (ws.ws_col);
}

int			get_termsize_y(void)
{
  struct winsize	ws;
  int			fd;

  fd = my_put_termcap(-1, NULL);
  if (ioctl(fd, TIOCGWINSZ, &ws) == -1)
    {
      perror("ioctl");
      return (1);
    }
  return (ws.ws_row - 1);
}
