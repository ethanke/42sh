/*
** pars_utils.c for pars_utils in /Users/leandr_g/Documents/Shared folder/42SH/src/parser/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Jun  5 01:14:24 2016 Gaëtan Léandre
** Last update Sun Jun  5 01:20:26 2016 Gaëtan Léandre
*/

#include		"main.h"

char   		 	*my_strcpy(char *dest, char *src)
{
  int   		i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char			*my_strcat_wm(char *s, char *s2)
{
  int	i;
  int	j;

  i = my_strlen(s);
  j = 0;
  while (s2[j])
    s[i++] = s2[j++];
  s[i] = '\0';
  return (s);
}
