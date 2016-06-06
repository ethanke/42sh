/*
** my_cat.c for  in /Users/ethankerdelhue/Documents/Shared/42sh/src/parser/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Jun  6 21:15:06 2016 Ethan Kerdelhue
** Last update Mon Jun  6 21:15:21 2016 Ethan Kerdelhue
*/

#include		"parser.h"

char			*my_cat(char *a, char *b)
{
  int			size;
  char			*str;
  int			i;
  int			j;

  size = my_strlen(a) + my_strlen(b) + 2;
  if ((str = malloc(size)) == NULL)
    return (NULL);
  i = 0;
  while (a[i])
    {
      str[i] = a[i];
      i++;
    }
  j = 0;
  while (b[j])
    {
      str[i] = b[j];
      i++;
      j++;
    }
  str[i] = '\0';
  return (str);
}
