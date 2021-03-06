/*
** modular_var.c for  in /home/sousa_v/rendu/psu/42_temp/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu May 26 00:08:24 2016 Victor Sousa
** Last update Mon Jun  6 23:27:58 2016 victor sousa
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
