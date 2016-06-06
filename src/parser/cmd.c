/*
** cmd.c for  in /Users/ethankerdelhue/Documents/Shared/42sh/parser/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Jun  1 22:13:03 2016 Ethan Kerdelhue
** Last update Mon Jun  6 06:14:23 2016 Ethan Kerdelhue
*/

#include	"parser.h"

int		check_last(t_pile *pile)
{
  t_pile	*tmp;

  tmp = pile;
  while (tmp->next)
    tmp = tmp->next;
  if (tmp)
    return (((my_strcmp(tmp->content, "<") == 0) ? (1) :
	     (my_strcmp(tmp->content, ">") == 0) ? (1) :
	     (my_strcmp(tmp->content, "<<") == 0) ? (1) :
	     (my_strcmp(tmp->content, ">>") == 0) ? (1) : (0)));
  return (0);
}
