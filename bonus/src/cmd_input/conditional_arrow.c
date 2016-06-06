/*
** conditional_arrow.c for  in /home/sousa_v/rendu/psu/42sh
** 
** Made by victor sousa
** Login   <sousa_v@epitech.net>
** 
** Started on  Mon Jun  6 22:13:44 2016 victor sousa
** Last update Mon Jun  6 22:14:11 2016 victor sousa
*/

#include	"main.h"
#include	"prompt.h"

int             if_ctrll(char *buff, t_edit_line *line)
{
  if (buff[0] == CTRLL && buff[1] == '\0')
    {
      my_clear_screen(line);
      return (-1);
    }
  return (0);
}

int             if_side(char *buff, t_edit_line *line)
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

int             if_side2(char *buff, t_edit_line *line)
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

int             if_delete(char *buff, t_edit_line *line)
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

int             if_paste(char *buff, t_edit_line *line)
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

