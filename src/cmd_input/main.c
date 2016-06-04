/*
** main.c for  in /home/sousa_v/perso/prompt_input/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Jun  3 14:59:12 2016 Victor Sousa
** Last update Sat Jun  4 05:17:42 2016 Victor Sousa
*/

#include	"prompt.h"

int		main(int ac, char **av, char **env)
{
  char		*str;
  t_edit_line	line;

  (void)ac;
  (void)av;
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

  while ((str = get_prompt_input(&line, env)) != NULL)
    {
      printf("your entered : %s\n", str);
      free(str);
    }
  return (0);
}
