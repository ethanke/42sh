/*
** term_mode.c for  in /home/sousa_v/perso/prompt_input/src/termcap/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Jun  4 03:48:45 2016 Victor Sousa
** Last update Sat Jun  4 21:25:20 2016 Victor Sousa
*/

#include	"prompt.h"

int			mode_raw(int fd)
{
  struct termios	t;

  if (tcgetattr(fd, &t) == -1)
    {
      perror("tcgetattr");
      return (EXIT_FAILURE);
    }
  t.c_lflag = t.c_lflag & ~ICANON;
  t.c_lflag = t.c_lflag & ~ECHO;
  t.c_cc[VMIN] = 0;
  t.c_cc[VTIME] = 100;
  if (tcsetattr(fd, TCSANOW, &t) == -1)
    {
      perror("tcsetattr");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			reset_mode(struct termios t, int fd)
{
  if (tcsetattr(fd, TCSANOW, &t) == -1)
    {
      perror("tcsetattr");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int			reset_save_mode(int type, int fd)
{
  static struct termios	t;
  static int		pass = 0;

  if (type == RESTORE)
    {
      if (pass == 0)
	{
	  dprintf(2, "Error mod not save\n");
	  return (EXIT_FAILURE);
	}
      return (reset_mode(t, fd));
    }
  if (type == SAVE)
    {
      if (tcgetattr(fd, &t) == -1)
	{
	  perror("tcgetattr");
	  return (EXIT_FAILURE);
	}
      pass = 1;
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}
