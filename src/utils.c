/*
** utils.c for minishell in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Sun Jan 24 16:46:33 2016 Gaëtan Léandre
** Last update Tue Apr 12 00:37:41 2016 Gaëtan Léandre
*/

#include 		"minishell.h"

int			my_strlen(char *str)
{
  int			i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
    i++;
  return (i);
}

void			my_putchar(char c)
{
  write(1, &c, 1);
}

void			my_putstr(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
}

int			my_strcmp(char *a, char *b)
{
  int			i;

  i = 0;
  if (my_strlen(a) != my_strlen(b))
    return (0);
  while (a[i])
    {
      if (a[i] != b[i])
	return (0);
      i++;
    }
  return (1);
}

char			*my_strcat(char *a, char *b)
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
  str[i++] = '/';
  j = 0;
  while (b[j])
    {
      str[i] = b[j];
      i++;
      j++;
    }
  str[i] = '\0';
  free(b);
  return (str);
}

char			*my_strcat_no_free(char *a, char *b)
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
  str[i++] = '/';
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
