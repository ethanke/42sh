/*
** concatString.c for  in /home/sousa_v/perso/my_string/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu Jun  2 19:29:42 2016 Victor Sousa
** Last update Mon Jun  6 19:08:16 2016 victor sousa
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

static String	norme_concat(t_char *cur, String string2,
			     String output, int pos)
{
  int		ite;
  t_char	*cur2;

  ite = -1;
  while (cur != NULL && cur->next != NULL && ++ite < pos)
    {
      if ((output->data = pushChar(output->data, cur->c)) == NULL)
	return (NULL);
      cur = cur->next;
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

String		concatStringAt(String string1, String string2, int pos)
{
  String	output;
  t_char	*cur;

  if ((output = malloc(sizeof(String))) == NULL)
    return (NULL);
  output->data = NULL;
  cur = string1->data;
  return (norme_concat(cur, string2, output, pos));
}
