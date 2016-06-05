/*
** copyStringFrom.c for  in /home/sousa_v/rendu/psu/42_temp/src/cmd_input/string/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Jun  5 16:13:58 2016 Victor Sousa
** Last update Sun Jun  5 21:14:49 2016 Victor Sousa
*/

#include	"my_string.h"

String		copyStringFrom(String string, int pos)
{
  String	output;
  t_char	*cur;
  int		ite;

  if ((output = malloc(sizeof(String))) == NULL)
    return (NULL);
  ite = 0;
  output->data = NULL;
  cur = string->data;
  while (cur != NULL && cur->next != NULL && ite < pos)
    {
      cur = cur->next;
      ite++;
    }
  if (cur == NULL)
    {
      if ((output->data = pushChar(output->data, '\0')) == NULL)
	return (NULL);
      return (output);
    }
  while (cur != NULL)
    {
      if ((output->data = pushChar(output->data, cur->c)) == NULL)
	return (NULL);
      cur = cur->next;
    }
  printString(output);
  return (output);
}
