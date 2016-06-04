/*
** modular_var.c for  in /home/sousa_v/rendu/psu/42_temp/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu May 26 00:08:24 2016 Victor Sousa
** Last update Sat Jun  4 05:18:16 2016 
*/

#include	"main.h"

int             modular_prog_status(char boolean, int value)
{
  static int    status = 1;

  if (boolean)
    status = value;
  return (status);
}

char            *my_strdup(char *str)
{
  char          *result;
  int           i;
  
  if ((result = malloc(1 + my_strlen(str))) == NULL)
    return (NULL);
  i = -1;
  while (str[++i])
    {
      result[i] = str[i];
    }
  result[i] = '\0';
  return (result);
}

char		*modular_pwd(char boolean, char *new_pwd)
{
  static char	*pwd = NULL;

  if (boolean && new_pwd)
    {
      if (pwd != NULL)
	free(pwd);
      pwd = my_strdup(new_pwd);
    }
  return (pwd);
}
