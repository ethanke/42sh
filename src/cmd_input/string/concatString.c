/*
** concatString.c for  in /home/sousa_v/perso/my_string/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu Jun  2 19:29:42 2016 Victor Sousa
** Last update Thu Jun  2 20:01:44 2016 Victor Sousa
*/

#include	"my_string.h"

String		concatString(String string1, String string2)
{
  String	output;
  t_char	*cur;

  if ((output = malloc(sizeof(String))) == NULL)
    return (NULL);
  output->data = NULL;
  cur = string1->data;
  while (cur != NULL)
    {
      if ((output->data = pushChar(output->data, cur->c)) == NULL)
	return (NULL);
      cur = cur->next;
    }
  freeString(string1);
  cur = string2->data;
  while (cur != NULL)
    {
      if ((output->data = pushChar(output->data, cur->c)) == NULL)
	return (NULL);
      cur = cur->next;
    }
  freeString(string2);
  return (output);
}
