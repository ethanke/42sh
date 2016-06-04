/*
** getPromptInput.c for  in /home/sousa_v/perso/prompt_input/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Jun  3 15:04:01 2016 Victor Sousa
** Last update Sat Jun  4 08:12:54 2016 Victor Sousa
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
  return (1);
}

char		*get_prompt_input(t_edit_line *line, char **env)
{
  int		ret;
  char		buff[10];

  init_edition_line(env, line);
  ret = 1;

  while (ret > 0)
    {
      term_refresh(line);
      printString(line->output_string);
      curseur(line->cur_pos_x, line->cur_pos_y);
      if ((ret = read(0, buff, 9)) == -1)
	break;
      buff[ret] = '\0';

      if (buff[0] == CTRLD && buff[1] == '\0')
	{
	  printf("\nctrl+d catched, leaving...\n");
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
	  if (line->cur_pos_x < get_termsize_x() && line->cur_pos_x < StringLenght(line->output_string))
	    line->cur_pos_x++;
	  continue;
	}
      if (my_prompt_strcmp(buff, KEY_START) == 1)
  	{
  	  line->cur_pos_x = 0;
  	  continue;
  	}
      if (my_prompt_strcmp(buff, KEY_END) == 1)
    	{
    	  line->cur_pos_x = StringLenght(line->output_string);
    	  continue;
    	}
      if (buff[0] == DEL && buff[1] == '\0')
	{
	  if (line->cur_pos_x > line->start_pos_x)
	    deleteCharAt(line->output_string, line->cur_pos_x-- - line->start_pos_x);
  	  continue;
  	}

      /* TODO */
      if (buff[0] == CTRLK && buff[1] == '\0')
	{
	  printf("CTRL-K\n");
	  continue;
	}
      if (buff[0] == CTRLY && buff[1] == '\0')
	{
	  printf("CTRL-Y\n");
	  continue;
	}
        if (buff[0] == CTRLU && buff[1] == '\0')
  	{
  	  printf("CTRL-U\n");
  	  continue;
  	}
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
