/*
** conditional_key.c for  in /home/sousa_v/rendu/psu/42sh
** 
** Made by victor sousa
** Login   <sousa_v@epitech.net>
** 
** Started on  Mon Jun  6 22:10:29 2016 victor sousa
** Last update Mon Jun  6 22:13:20 2016 victor sousa
*/

#include	"main.h"
#include	"prompt.h"

int		init_edition_line(char **env, t_edit_line *line)
{
  char		*s;

  if ((line->fd_tty = open("/dev/tty", O_RDWR)) == -1 ||
      (s = get_env_var("TERM", env)) == NULL || tgetent(NULL, s) != 1)
    return (0);
  my_put_termcap(line->fd_tty, NULL);
  if (reset_save_mode(SAVE, line->fd_tty) == EXIT_FAILURE)
    return (0);
  if (init_capacity_termcap(&line->termcap) == -1)
    return (0);
  get_pos_curser(&line->start_pos_x, &line->start_pos_y, line->fd_tty);
  line->cur_pos_x = line->start_pos_x;
  line->cur_pos_y = line->start_pos_y;
  line->output_string = formString("");
  modular_clip(1, formString(""), 0);
  return (1);
}

int             get_last_history_id()
{
  if (modular_history(0, NULL) == NULL)
    return (-1);
  while (modular_history(0, NULL)->next != NULL)
    modular_history(1 , modular_history(0, NULL)->next);
  return (modular_history(0, NULL)->id);
}

int             get_read_ret(t_edit_line *line, char *buff, char *out, int ret)
{
  struct pollfd pfd;
  int           pr;

  set_value_start(line, &pfd, &pr);
  if (pr > 0)
    {
      if ((ret = read(0, buff, 9)) == -1)
        return (-1);
      buff[ret] = '\0';
    }
  else
    {
      if (modular_prog_status(0, 0) == 2)
        {
          modular_prog_status(1, 1);
          write(1, "\n", 1);
          line->output_string = formString("");
          out = StringToArray(line->output_string, STRING_NO_FREE);
          (void)out;
          return (-3);
        }
      else
        return (-2);
    }
  return (ret);
}

int             if_ctrld(char *buff, t_edit_line *line)
{
  if (buff[0] == CTRLD && buff[1] == '\0')
    {
      freeString(line->output_string);
      return (-1);
    }
  return (0);
}

int             if_enter(char *buff)
{
  if (buff[0] == ENTER && buff[1] == '\0')
    {
      write(1, "\n", 1);
      return (-1);
    }
  return (0);
}
