/*
** epur.c for  in /Users/ethankerdelhue/Documents/Shared/42sh/parser/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue May 31 06:44:24 2016 Ethan Kerdelhue
** Last update Tue May 31 14:39:43 2016 Ethan Kerdelhue
*/

#include 	"parser.h"

int		count_size_sep(char *str, char **sep)
{
  int		i;
  int		j;
  int		size;

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

char		*epur_opt(char *str, char **lim, int i, int k)
{
  int		j;
  char		*new;
  char		flag;

  if ((new = malloc(count_size_sep(str, lim) + 1)) == NULL)
    return (NULL);
  while (str[++i])
    {
      flag = 1;
      j = -1;
      while (lim[++j])
	  if ((my_strncmp(str + i, lim[j], my_strlen(lim[j])) == 0))
	      if (str[i + 1] != '|' && str[i - 1] != '|')
		{
		  new[k] = '\0';
		  new = my_strcat(new, my_strcat(" ", my_strcat(lim[j], " ")));
		  k += my_strlen(lim[j]) + 2;
		  i += my_strlen(lim[j]) - 1;
		  flag = 0;
		}
      if (flag)
	new[k++] = str[i];
    }
  new[k] = 0;
  return (new);
}

char		*epur_sep(char *str, char **delim, int i, int k)
{
  int		j;
  char		*new;
  char		flag;

if ((new = malloc(count_size_sep(str, delim) + 1)) == NULL)
    return (NULL);
  while (str[++i])
    {
      flag = 1;
      j = -1;
      while (delim[++j])
	  if (my_strncmp(str + i, delim[j], my_strlen(delim[j])) == 0)
	    {
	      new[k] = '\0';
	      new = my_strcat(new, my_strcat(" ", my_strcat(delim[j], " ")));
	      k += my_strlen(delim[j]) + 2;
	      i += my_strlen(delim[j]) - 1;
	      flag = 0;
	    }
      if (flag)
	new[k++] = str[i];
    }
  new[k] = 0;
printf("NEW -> %s \n", new);
  return (new);
}

char		*epur_string(char *str)
{
  char		*new;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((new = malloc(my_strlen(str) + 1)) == NULL)
    return (0);
  while (str[i] == ' ')
    i++;
  while (str[i])
    {
      if (str[i] != ' ' || (str[i] == ' ' && str[i - 1] != ' '))
	{
	  new[j] = str[i];
	  j++;
	}
      i++;
    }
  new[j] = 0;
  return (new);
}
