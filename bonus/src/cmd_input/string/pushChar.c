/*
** pushChar.c for  in /home/sousa_v/perso/my_string/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu Jun  2 18:32:21 2016 Victor Sousa
** Last update Sat Jun  4 06:01:33 2016 Victor Sousa
*/

#include	"my_string.h"

t_char		*pushChar(t_char *string, char c)
{
  t_char	*new_char;
  t_char	*tmp;

  if ((new_char = malloc(sizeof(t_char))) == NULL)
    return (NULL);
  new_char->c = c;
  new_char->next = NULL;
  if (string == NULL)
    return (new_char);
  else
    {
      tmp = string;
      while (tmp->next != NULL)
	{
	  tmp = tmp->next;
	}
      tmp->next = new_char;
    }
  return (string);
}

t_char			*pushCharAt(t_char *string, char c, int place)
{
  t_char		*new_char;
  t_char		*tmp;
  int			ite;

  if ((new_char = malloc(sizeof(t_char))) == NULL)
    return (NULL);
  ite = 1;
  new_char->c = c;
  new_char->next = NULL;
  if (string == NULL)
    return (new_char);
  else
    {
      tmp = string;
      while (tmp->next != NULL && ite < place)
	{
	  tmp = tmp->next;
	  ite++;
	}
      if (tmp->next != NULL)
	new_char->next = tmp->next;
      tmp->next = new_char;
    }
  return (string);
}
