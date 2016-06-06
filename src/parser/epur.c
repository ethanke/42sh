/*
** epur.c for  in /Users/ethankerdelhue/Documents/Shared/42sh/parser/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Tue May 31 06:44:24 2016 Ethan Kerdelhue
** Last update Mon Jun  6 22:51:42 2016 victor sousa
*/

#include 	"parser.h"

char                    *my_epurstr(char *in, char *to_delete)
{
  char                  *out;
  int                   i;
  int                   j;

  if (in == NULL || (out = malloc(sizeof(char) * (my_strlen(in) + 1))) == NULL)
    return (NULL);
  j = 0;
  i = 0;
  while (in[i])
    {
      if (is_a_to_delete(in[i], to_delete))
        {
          if (in[i - 1] && in[i - 1] != ';')
            out[j++] = ' ';
          while (is_a_to_delete(in[i], to_delete))
            i++;
          if (in[i] == '\0' || in[i] == ';')
            j--;
        }
      else
        out[j++] = in[i++];
    }
  out[j] = '\0';
  return (out);
}

char		*epur_opt(char *str, char **lim, int i, int k)
{
  int		j;
  char		*new;

  str = my_epurstr(str, "\t ");
  if ((new = malloc(count_size_sep(str, lim) + 1)) == NULL)
    return (NULL);
  while (str[++i])
    {
      j = -1;
      while (lim[++j])
	if (my_strncmp(str + i, lim[j], my_strlen(lim[j])) == 0)
	  {
	    if (str[i] == '|' && str[i + 1] != '|')
	      {
		new[k] = '\0';
		sprintf(new, "%s  %s  ", new, lim[j]);
		i += my_strlen(lim[j]);
		k += my_strlen(lim[j]) + 4;
	      }
	  }
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
	      new = my_strcat_wm(new, my_cat(" ", my_cat(delim[j], " ")));
	      k += my_strlen(delim[j]) + 2;
	      i += my_strlen(delim[j]) - 1;
	      flag = 0;
	    }
      if (flag)
        new[k++] = str[i];
    }
  new[k] = 0;
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
