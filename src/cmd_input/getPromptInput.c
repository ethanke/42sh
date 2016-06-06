/*
** getPromptInput.c for  in /home/sousa_v/perso/prompt_input/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Jun  3 15:04:01 2016 Victor Sousa
** Last update Mon Jun  6 00:52:26 2016 Victor Sousa
*/

#include	"prompt.h"

int	init_edition_line(char **env, t_edit_line *line)
{
  char	*s;

  if ((line->fd_tty = open("/dev/tty", O_RDWR)) == -1 ||
      (s = get_env_var("TERM", env)) == NULL || tgetent(NULL, s) != 1)
    return (0);
  my_put_termcap(line->fd_tty, NULL);
  if (reset_save_mode(SAVE, line->fd_tty) == EXIT_FAILURE)
    return (0);
  init_capacity_termcap(&(line->termcap));
  get_pos_curser(&line->start_pos_x, &line->start_pos_y, line->fd_tty);
  line->cur_pos_x = line->start_pos_x;
  line->cur_pos_y = line->start_pos_y;
  line->output_string = formString("");
  modular_clip(1, formString(""), 0);
  return (1);
}

char		*get_prompt_input(t_edit_line *line, char **env)
{
  int		ret;
  char		buff[10];
  struct pollfd pfd = {0,0,0};
  int		pr;

  init_edition_line(env, line);
  ret = 1;

  while (ret > 0)
    {
      term_refresh(line);
      printString(line->output_string);
      curseur(line->cur_pos_x, line->cur_pos_y);

      pfd.fd = STDIN_FILENO;
      pfd.events = POLLIN;
      pr = poll(&pfd, 1, 5000);

      if (pr > 0)
	{
	  if ((ret = read(0, buff, 9)) == -1)
	    break;
	  buff[ret] = '\0';
	}
      else
	{
	  if (modular_prog_status(0, 0) == 2)
	    {
	      modular_prog_status(1, 1);
	      write(1, "\n", 1);
	      freeString(line->output_string);
	      line->output_string = formString("");
	      return (StringToArray(line->output_string, STRING_FREE));
	    }
	  else
	    continue;
	}

      if (buff[0] == CTRLD && buff[1] == '\0')
	{
	  freeString(line->output_string);
	  return (NULL);
	}
      if (buff[0] == ENTER && buff[1] == '\0')
  	{
  	  write(1, "\n", 1);
  	  break;
  	}
      if (buff[0] == CTRLL && buff[1] == '\0')
  	{
  	  my_clear_screen(line);
  	  continue;
  	}
      if (my_prompt_strcmp(buff, KEY_LEFT) == 1)
	{
	  if (line->cur_pos_x > line->start_pos_x)
	    line->cur_pos_x--;
	  continue;
	}
      if (my_prompt_strcmp(buff, KEY_RIGHT) == 1)
	{
	  if (line->cur_pos_x < get_termsize_x() &&
	      line->cur_pos_x < StringLenght(line->output_string) + line->start_pos_x)
	    line->cur_pos_x++;
	  continue;
	}
      if (my_prompt_strcmp(buff, KEY_START) == 1 ||
	  (buff[0] == CTRLA && buff[1] == '\0'))
  	{
  	  line->cur_pos_x = line->start_pos_x;
  	  continue;
  	}
      if (my_prompt_strcmp(buff, KEY_END) == 1 ||
	  (buff[0] == CTRLE && buff[1] == '\0'))
    	{
    	  line->cur_pos_x = StringLenght(line->output_string) + line->start_pos_x;
    	  continue;
    	}
      if (buff[0] == DEL && buff[1] == '\0')
	{
	  if (line->cur_pos_x > line->start_pos_x)
	    deleteCharAt(line->output_string, line->cur_pos_x-- - line->start_pos_x);
  	  continue;
  	}
      if (buff[0] == 0x1B && buff[1] == 0x5B && buff[2] == 0x33 &&
	  buff[3] == 0x7E && buff[4] == '\0')
  	{
	  printf("   %d\n", line->cur_pos_x - line->start_pos_x + 1);
	  deleteCharAt(line->output_string, line->cur_pos_x - line->start_pos_x + 1);
    	  continue;
    	}
      if (buff[0] == CTRLK && buff[1] == '\0')
        {
	  modular_clip(1, line->output_string, line->cur_pos_x - line->start_pos_x);
	  deleteAfterI(line->output_string, line->cur_pos_x - line->start_pos_x);
	  continue;
        }
      if (buff[0] == CTRLY && buff[1] == '\0')
	{
	  line->output_string = concatStringAt(line->output_string, modular_clip(0, NULL, 0), line->cur_pos_x - line->start_pos_x);
	  line->cur_pos_x += StringLenght(modular_clip(0, NULL, 0));
	  continue;
	}
      if (buff[0] == CTRLU && buff[1] == '\0')
	{
	  modular_clip(1, line->output_string, 0);
	  line->cur_pos_x -= StringLenght(line->output_string);
	  freeString(line->output_string);
	  line->output_string = formString("");
	  continue;
	}

      /* TODO */
        if (my_prompt_strcmp(buff, KEY_UP) == 1)
  	{
  	  freeString(line->output_string);
  	  line->output_string = formString("history up");
  	  line->cur_pos_x = line->start_pos_x + StringLenght(line->output_string);
  	  continue;
  	}
        if (my_prompt_strcmp(buff, KEY_DOWN) == 1)
  	{
  	  freeString(line->output_string);
  	  line->output_string = formString("history down");
  	  line->cur_pos_x = line->start_pos_x + StringLenght(line->output_string);
  	  continue;
  	}
      /* TODO */

      line->output_string->data = pushCharAt(line->output_string->data, buff[0], line->cur_pos_x++);
    }
  return (StringToArray(line->output_string, STRING_FREE));
}
