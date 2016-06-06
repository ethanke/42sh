/*
** getPromptInput.c for  in /home/sousa_v/perso/prompt_input/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Jun  3 15:04:01 2016 Victor Sousa
** Last update Mon Jun  6 21:56:38 2016 victor sousa
*/

#include	"main.h"
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
  if (init_capacity_termcap(&line->termcap) == -1)
    return (0);
  get_pos_curser(&line->start_pos_x, &line->start_pos_y, line->fd_tty);
  line->cur_pos_x = line->start_pos_x;
  line->cur_pos_y = line->start_pos_y;
  line->output_string = formString("");
  modular_clip(1, formString(""), 0);
  return (1);
}

int		get_last_history_id()
{
  if (modular_history(0, NULL) == NULL)
    return (-1);
  while (modular_history(0, NULL)->next != NULL)
    modular_history(1 , modular_history(0, NULL)->next);
  return (modular_history(0, NULL)->id);
}

int		get_read_ret(t_edit_line *line, char *buff, char *out, int ret)
{
  struct pollfd pfd;
  int		pr;

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

int		if_ctrld(char *buff, t_edit_line *line)
{
  if (buff[0] == CTRLD && buff[1] == '\0')
    {
      freeString(line->output_string);
      return (-1);
    }
  return (0);
}

int		if_enter(char *buff)
{
  if (buff[0] == ENTER && buff[1] == '\0')
    {
      write(1, "\n", 1);
      return (-1);
    }
  return (0);
}

int		if_ctrll(char *buff, t_edit_line *line)
{
  if (buff[0] == CTRLL && buff[1] == '\0')
    {
      my_clear_screen(line);
      return (-1);
    }
  return (0);
}

int		if_side(char *buff, t_edit_line *line)
{
  if (my_prompt_strcmp(buff, KEY_LEFT) == 1)
    {
      if (line->cur_pos_x > line->start_pos_x)
	line->cur_pos_x--;
      return (-1);
    }
  if (my_prompt_strcmp(buff, KEY_RIGHT) == 1)
    {
      if (line->cur_pos_x < get_termsize_x() &&
	  line->cur_pos_x < StringLenght(line->output_string)
	  + line->start_pos_x)
	line->cur_pos_x++;
      return (-1);
    }
  return (0);
}

int		if_side2(char *buff, t_edit_line *line)
{
  if (my_prompt_strcmp(buff, KEY_START) == 1 ||
      (buff[0] == CTRLA && buff[1] == '\0'))
    {
      line->cur_pos_x = line->start_pos_x;
      return (-1);
    }
  if (my_prompt_strcmp(buff, KEY_END) == 1 ||
      (buff[0] == CTRLE && buff[1] == '\0'))
    {
      line->cur_pos_x = StringLenght(line->output_string)
	+ line->start_pos_x;
      return (-1);
    }
  return (0);
}

int		if_delete(char *buff, t_edit_line *line)
{
  if (buff[0] == DEL && buff[1] == '\0')
    {
      if (line->cur_pos_x > line->start_pos_x)
	deleteCharAt(line->output_string, line->cur_pos_x--
		     - line->start_pos_x);
      return (-1);
    }
  if (buff[0] == 0x1B && buff[1] == 0x5B && buff[2] == 0x33 &&
      buff[3] == 0x7E && buff[4] == '\0')
    {
      deleteCharAt(line->output_string, line->cur_pos_x -
		   line->start_pos_x + 1);
      return (-1);
    }
  return (0);
}

int		if_paste(char *buff, t_edit_line *line)
{
  if (buff[0] == CTRLK && buff[1] == '\0')
    {
      modular_clip(1, line->output_string, line->cur_pos_x
		   - line->start_pos_x);
      deleteAfterI(line->output_string, line->cur_pos_x
		   - line->start_pos_x);
      return (-1);
    }
  if (buff[0] == CTRLY && buff[1] == '\0')
    {
      line->output_string =
	concatStringAt(line->output_string, modular_clip(0, NULL, 0),
		       line->cur_pos_x - line->start_pos_x);
      line->cur_pos_x += StringLenght(modular_clip(0, NULL, 0));
      return (-1);
    }
  if (buff[0] == CTRLU && buff[1] == '\0')
    {
      modular_clip(1, line->output_string, 0);
      line->cur_pos_x -= StringLenght(line->output_string);
      freeString(line->output_string);
      line->output_string = formString("");
      return (-1);
    }
  return (0);
}

int		if_history(char *buff, t_edit_line *line)
{
  if (my_prompt_strcmp(buff, KEY_UP) == 1)
    {
      if (modular_history(0, NULL) != NULL)
	func_key_up(line);
      line->cur_pos_x = line->start_pos_x
	+ StringLenght(line->output_string);
      return (-1);
    }
  if (my_prompt_strcmp(buff, KEY_DOWN) == 1)
    {
      func_key_down(line);
      line->cur_pos_x = line->start_pos_x
	+ StringLenght(line->output_string);
      return (-1);
    }
  return (0);
}

int		if_auto(char *buff, t_edit_line *line)
{
  int		pos;

  if (buff[0] == TAB && buff[1] == '\0')
    {
      pos = line->cur_pos_x - line->start_pos_x;
      auto_complete(line->output_string, &pos);
      line->cur_pos_x = pos + line->start_pos_x;
      return (-1);
    }
  return (0);
}

int		if_global(char *buff, t_edit_line *line)
{
  if (if_ctrll(&buff[0], line) == -1)
    return (-1);
  if (if_side(&buff[0], line) == -1)
    return (-1);
  if (if_side2(&buff[0], line) == -1)
    return (-1);
  if (if_delete(&buff[0], line) == -1)
    return (-1);
  if (if_paste(&buff[0], line) == -1)
    return (-1);
  if (if_history(&buff[0], line) == -1)
    return (-1);
  if (if_auto(&buff[0], line) == -1)
    return (-1);
  return (0);
}

int		while_ret(t_edit_line *line, char *out)
{
  int		ret;
  char		buff[10];

  ret = 1;
  while (ret > 0)
    {
      ret = get_read_ret(line, &buff[0], out, -1);
      if (ret == -1)
	return (-1);
      if (ret == -2)
	continue;
      if (ret == -3)
	break;
      if (if_ctrld(&buff[0], line) == -1)
	return (-1);
      if (if_enter(&buff[0]) == -1)
	break;
      if (if_global(&buff[0], line) == -1)
	continue;
      line->output_string->data = pushCharAt(line->output_string->data,
					     buff[0], line->cur_pos_x++ -
					     line->start_pos_x);
    }
 return (0);
}

char		*get_prompt_input(t_edit_line *line, char **env)
{
  char		*out;

  if (get_tty(env, line))
    return (get_next_line(0));
  out = NULL;
  modular_history(1, add_to_history(modular_history(0, NULL),
				    get_last_history_id() + 1,
				    StringToArray(line->output_string,
						  STRING_NO_FREE)));
  while (modular_history(0, NULL)->next != NULL)
    modular_history(1 , modular_history(0, NULL)->next);
  if (while_ret(line, out) == -1)
    return (NULL);
  return (StringToArray(line->output_string, STRING_FREE));
}
