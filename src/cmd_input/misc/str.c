/*
** str.c for  in /home/sousa_v/perso/prompt_input/src/misc/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Jun  4 03:33:00 2016 Victor Sousa
** Last update Sat Jun  4 08:09:55 2016 Victor Sousa
*/

#include	"prompt.h"

void		my_strncpy(char *dest, char *src, int n)
{
  int		i;

  i = 0;
  if ((dest != NULL) && (src != NULL))
    {
      if (n == -1)
        {
          while (src[i] != '\0')
            {
              dest[i] = src[i];
              i++;
            }
        }
      else
        {
          while (i < n)
            {
              dest[i] = src[i];
              i++;
            }
        }
      dest[i] = '\0';
    }
}

int		my_prompt_strcmp(char *str1, char *str2)
{
  int		indice;

  indice = 0;
  if (str1 == NULL || str2 == NULL ||
      strlen(str1) != strlen(str2))
    return (0);
  while (str1[indice] != '\0' && str2[indice] != '\0')
    {
      if (str1[indice] != str2[indice])
	return (0);
      indice = indice + 1;
    }
  return (1);
}

int		my_strncmp(char *s1, char *s2, int n)
{
  int		i;
  int		len;
  int		len2;

  i = 0;
  if ((s1 == NULL) || (s2 == NULL))
    return (s1 - s2);
  len = strlen(s1);
  len2 = strlen(s2);
  if (len > len2)
    len = len2;
  if ((len > n) && (n != -1))
    len = n;
  while (i < len)
    {
      if (s1[i] != s2[i])
        return (s1[i] - s2[i]);
      i = i + 1;
    }
  if (len == n)
    return (0);
  return (s1[i] - s2[i]);
}
