/*
** concatString.c for  in /home/sousa_v/perso/my_string/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu Jun  2 19:29:42 2016 Victor Sousa
** Last update Sun Jun  5 22:18:46 2016 Victor Sousa
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

String		concatStringAt(String string1, String string2, int pos)
{
  String	output;
  t_char	*cur;
  t_char	*cur2;
  int		ite;

  if ((output = malloc(sizeof(String))) == NULL)
    return (NULL);
  ite = 0;
  output->data = NULL;
  cur = string1->data;
  while (cur != NULL && cur->next != NULL && ite < pos)
    {
      if ((output->data = pushChar(output->data, cur->c)) == NULL)
	return (NULL);
      cur = cur->next;
      ite++;
    }
  cur2 = string2->data;
  while (cur2 != NULL)
    {
      if ((output->data = pushChar(output->data, cur2->c)) == NULL)
	return (NULL);
      cur2 = cur2->next;
    }
  while (cur != NULL)
    {
      if ((output->data = pushChar(output->data, cur->c)) == NULL)
	return (NULL);
      cur = cur->next;
    }
  return (output);
}
