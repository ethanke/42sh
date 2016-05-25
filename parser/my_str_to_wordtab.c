/*
** my_str_to_wordtab.c for  in /Users/ethankerdelhue/Documents/Shared/minishell/minishell2/utils/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue Mar 29 15:11:34 2016 Ethan Kerdelhue
** Last update Wed May 25 16:55:58 2016 Ethan Kerdelhue
*/

#include 	"parser.h"

char		check(char c, char *delim)
{
  int		i;

  i = -1;
  while (delim[++i])
    if (delim[i] == c)
      return (0);
  return (c);
}

int		countchars(char *str, char *delim)
{
  int		i;

  i = 0;
  while (check(str[i], delim))
    i++;
  return (i + 1);
}

int		countwords(char *str, char *delim)
{
  int		i;
  int		count;

  i = 0;
  count = 1;
  while (str[i] != '\0')
  {
    if (!check(str[i], delim))
      {
	count++;
	while (str[i] && !check(str[i], delim))
	  i++;
      }
      if (str[i])
        i++;
   }
   return (count + 1);
}

char		**my_str_to_wordtab(char *str, char *delim)
{
  int		i;
  int		j;
  int		k;
  char		**tab;

  i = 0;
  j = -1;
  tab = malloc(countwords(str, delim) * sizeof(char *));
  while (str[i] && !check(str[i], delim))
    i++;
  while (str[i])
    {
      tab[++j] = malloc(countchars(&str[i], delim));
      k = -1;
      while (check(str[i], delim))
	tab[j][++k] = str[i++];
      tab[j][++k] = 0;
      while (str[i] && !check(str[i], delim))
	i++;
    }
  tab[++j] = NULL;
  return (tab);
}
