/*
** list.h for list.h in /home/leandr_g/perso/list
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Tue Nov 17 11:29:13 2015 Gaëtan Léandre
** Last update Mon Jun  6 18:52:50 2016 victor sousa
*/

#ifndef 		LIST_H_
# define 		LIST_H_

#include 		<stdlib.h>

typedef	struct 		s_list
{
  char		    	*name;
  char			*params;
  struct s_list		*prev;
  struct s_list		*next;
}      			t_list;

typedef struct		s_dlist
{
  int			size;
  char			**env;
  char			*pwd;
  char			**path;
  t_list		*start;
  t_list		*end;
}			t_dlist;

t_dlist			*create_dlist();
t_list			*create_list(char *name, char *params);
void			free_tables(char **str);
void			insert_list_end(t_list *list, t_dlist *dlist);
t_list			*pop_list_start(t_dlist *dlist);
void			remove_list(t_dlist *dlist);
void			pop_list(t_list *list, t_dlist *dlist);

#endif			/*LIST_H_*/
