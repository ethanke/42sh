/*
** modular_var.c for  in /home/sousa_v/rendu/psu/42_temp/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu May 26 00:08:24 2016 Victor Sousa
** Last update Mon Jun  6 17:02:44 2016 Victor Sousa
*/

#include		"main.h"
#include		"my_string.h"

int             	modular_prog_status(char boolean, int value)
{
  static int    	status = 1;

  if (boolean)
    status = value;
  return (status);
}

char			*modular_pwd(char boolean, char *new_pwd)
{
  static char		*pwd = NULL;

  if (boolean && new_pwd)
    {
      if (pwd != NULL)
	free(pwd);
      pwd = my_strdup(new_pwd);
    }
  return (pwd);
}

t_history		*modular_history(char boolean, t_history *new_history)
{
  static t_history	*history = NULL;

  if (boolean && new_history)
    history = new_history;
  return (history);
}

String			modular_clip(char boolean, String new_buff, int pos)
{
  static String 	buff = NULL;

  if (boolean && new_buff)
    {
      if (buff != NULL)
	freeString(buff);
      buff = copyStringFrom(new_buff, pos);
    }
  return (buff);
}

t_edit_line		*modular_line(char boolean, t_edit_line *new_line)
{
  static t_edit_line	*line = NULL;

  if (boolean && new_line)
    {
      line = new_line;
    }
  return (line);
}
