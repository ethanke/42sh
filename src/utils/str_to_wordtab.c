/*
** str_to_wordtable.c for str_to_wordtable in /Users/leandr_g/Documents/Shared folder/PSU_2015_minishell2/src/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sat Apr  9 01:06:04 2016 Gaëtan Léandre
** Last update Mon Jun  6 23:31:40 2016 victor sousa
*/

#include		"main.h"

int             my_strncmp(char *s1, char *s2, int n)
{
  int           i;
  int           len;
  int           len2;

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

int			is_separate(char c, char *str)
{
  int			i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (1);
      i++;
    }
  return (0);
}

char			*size_word(char *str, char *separate, int *i)
{
  char			*result;
  int			size;
  int			j;

  size = 0;
  j = *i;
  while (str[j] && is_separate(str[j], separate) == 0)
    {
      size++;
      j++;
    }
  if ((result = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  j = 0;
  while (str[*i] && is_separate(str[*i], separate) == 0)
    {
      result[j] = str[*i];
      j++;
      (*i)++;
    }
  (*i)--;
  result[j] = '\0';
  return (result);
}

char			**str_to_wordtable(char *str, char *separate)
{
  char			**table;
  int			words;
  int			i;

  words = 0;
  i = -1;
  while (str[++i])
      if (i - 1 < 0 || (is_separate(str[i], separate) == 1
			&& is_separate(str[i - 1], separate) == 0))
	words++;
  if (words == 0 || (table = malloc(sizeof(char *) * (words + 1))) == NULL)
    return (NULL);
  i = -1;
  words = 0;
  while (str[++i])
    {
      if (is_separate(str[i], separate) == 0)
	{
	  if ((table[words] = size_word(str, separate, &i)) == NULL)
	    return (NULL);
	  words++;
	}
    }
  table[words] = NULL;
  return (table);
}
