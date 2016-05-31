/*
** my_strcat.c for mysh in /Users/ethankerdelhue/Documents/Shared/mysh/src/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Sun Jan 24 04:23:26 2016 Ethan Kerdelhue
** Last update Mon May 30 17:27:39 2016 Ethan Kerdelhue
*/

#include 	"parser.h"

char 	*my_strcat(char *dest, char *src)
{
  char	*new;
  int	i;
  int	j;

  i = -1;
  j = 0;
  new = malloc(my_strlen(dest) + my_strlen(src) + 1);
  while (dest[++i])
    new[i] = dest[i];
  while (src[j])
    {
      new[i] = src[j++];
      i++;
    }
  new[i] = 0;
  return (new);
}
