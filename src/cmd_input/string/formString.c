/*
** formString.c for  in /home/sousa_v/perso/my_string/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu Jun  2 17:48:04 2016 Victor Sousa
** Last update Thu Jun  2 19:16:01 2016 Victor Sousa
*/

#include	"my_string.h"

String		formString(const char *str_raw)
{
  String	output;
  int		ite;

  if ((output = malloc(sizeof(String))) == NULL)
    return (NULL);
  output->data = NULL;
  ite = 0;
  while (str_raw[ite])
    {
      if ((output->data = pushChar(output->data, str_raw[ite])) == NULL)
	return (NULL);
      ite++;
    }
  return (output);
}
