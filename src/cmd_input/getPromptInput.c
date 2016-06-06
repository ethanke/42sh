/*
** getPromptInput.c for  in /home/sousa_v/perso/prompt_input/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Jun  3 15:04:01 2016 Victor Sousa
** Last update Mon Jun  6 22:14:20 2016 victor sousa
*/

#include	"main.h"
#include	"prompt.h"

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
