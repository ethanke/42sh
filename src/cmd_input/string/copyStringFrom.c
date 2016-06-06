/*
** copyStringFrom.c for  in /home/sousa_v/rendu/psu/42_temp/src/cmd_input/string/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sun Jun  5 16:13:58 2016 Victor Sousa
** Last update Mon Jun  6 19:03:20 2016 victor sousa
*/

#include	"my_string.h"

static String	norme_string(t_char *cur, int pos, String output)
{
  int		ite;

  ite = 0;
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
  return (output);
}

String		copyStringFrom(String string, int pos)
{
  String	output;
  t_char	*cur;

  if ((output = malloc(sizeof(String))) == NULL)
    return (NULL);
  output->data = NULL;
  cur = string->data;
  return (norme_string(cur, pos, output));
}
