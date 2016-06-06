/*
** utils.c for  in /home/kerdel_e/Shared/42sh/src/parser
**
** Made by Kerdelhue Ethan
** Login   <kerdel_e@epitech.net>
**
** Started on  Mon Jun  6 21:19:10 2016 Kerdelhue Ethan
** Last update Mon Jun  6 21:19:13 2016 Kerdelhue Ethan
*/

#include		"parser.h"

int			count_size_sep(char *str, char **sep)
{
  int			i;
  int			j;
  int			size;

  i = -1;
  j = 0;
  size = my_strlen(str);
  while (str[++i])
    {
      j = 0;
      while (sep[j])
	{
	  if (my_strncmp(&str[i], sep[j], my_strlen(sep[j])) == 0)
	    size += 2;
	  j++;
	}
    }
  return (size);
}

int                     is_a_to_delete(char c, char *to_delete)
{
  int                   i;

  i = -1;
  while (to_delete[++i])
    {
      if (c == to_delete[i])
	return (1);
    }
  return (0);
}
