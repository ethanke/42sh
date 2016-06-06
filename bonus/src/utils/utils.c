/*
** utils.c for minishell in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Sun Jan 24 16:46:33 2016 Gaëtan Léandre
** Last update Mon Jun  6 15:51:04 2016 Gaëtan Léandre
*/

#include 		"main.h"

char			*my_strcat_first(char *a, char *b)
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
  free(a);
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

char			*my_strcat_no_free_b(char *a, char *b)
{
  int			size;
  char			*str;
  int			i;
  int			j;

  size = my_strlen(a) + my_strlen(b) + 1;
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
