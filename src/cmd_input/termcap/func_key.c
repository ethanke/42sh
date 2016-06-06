/*
** PromptFunc.c for  in /Users/ethankerdelhue/Documents/Shared/42sh/src/cmd_input/termcap/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Jun  6 18:12:09 2016 Ethan Kerdelhue
** Last update Mon Jun  6 20:51:56 2016 victor sousa
*/

#include		"main.h"

char			*get_tty(char **env, t_edit_line *line)
{
  if (isatty(0) != 1 || init_edition_line(env, line) == 0)
    {
      reset_save_mode(RESTORE, line->fd_tty);
      return (get_next_line(0));
    }
  else
    return (NULL);
}

int			set_value_start(t_edit_line *line,
					struct pollfd *pfd,
					int *pr)
{
  if (modular_history(0, NULL)->cmd != NULL)
    free(modular_history(0, NULL)->cmd);
  modular_history(0, NULL)->cmd = StringToArray(line->output_string,
						STRING_NO_FREE);
  term_refresh(line);
  printString(line->output_string);
  curseur(line->cur_pos_x, line->cur_pos_y);
  pfd->fd = STDIN_FILENO;
  pfd->events = POLLIN;
  *pr = poll(pfd, 1, 5000);
  return (0);
}

int			func_key_up(t_edit_line *line)
{
  freeString(line->output_string);
  if (modular_history(0, NULL)->prev == NULL)
    {
      line->output_string = formString(modular_history(0, NULL)->cmd);
      modular_history(1, modular_history(0, NULL)->prev);
    }
  else
    {
      modular_history(1, modular_history(0, NULL)->prev);
      line->output_string = formString(modular_history(0, NULL)->cmd);
    }
  return (0);
}

int			func_key_down(t_edit_line *line)
{
  if (modular_history(0, NULL) != NULL)
    {
      freeString(line->output_string);
            if (modular_history(0, NULL)->next == NULL)
	{
	  line->output_string = formString(modular_history(0, NULL)->cmd);
	  modular_history(1, modular_history(0, NULL)->next);
	}
      else
	{
	  modular_history(1, modular_history(0, NULL)->next);
	  line->output_string = formString(modular_history(0, NULL)->cmd);
	}
    }
  return (0);
}
