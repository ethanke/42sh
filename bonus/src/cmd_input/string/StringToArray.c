/*
** stringToArray.c for  in /home/sousa_v/perso/prompt_input/src/string/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Jun  4 05:03:47 2016 Victor Sousa
** Last update Sat Jun  4 05:11:55 2016 Victor Sousa
*/

#include	"my_string.h"

char		*StringToArray(String string, char needFree)
{
  char		*out;
  int		ite;
  t_char	*c;

  if ((out  = malloc(sizeof(char) * (StringLenght(string) + 1))) == NULL)
    return (NULL);
  ite = 0;
  c = string->data;
  while (c != NULL)
    {
      out[ite++] = c->c;
      c = c->next;
    }
  out[ite] = '\0';
  if (needFree == STRING_FREE)
    freeString(string);
  return (out);
}
