/*
** list.c for list in /Users/leandr_g/Documents/Shared folder/42SH/src/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Jun  6 02:26:26 2016 Gaëtan Léandre
** Last update Mon Jun  6 02:44:37 2016 Gaëtan Léandre
*/

typedef struct		s_list
{
  int			status;
  char			*cmd;
  struct s_list		*prev;
  struct s_list		*next;
}			t_list;

t_list			*add_to_list(t_list *list, int status, char *cmd)
{
  t_list		*tmp;

  if ((tmp = malloc(sizeof(t_list))) == NULL)
    return (list);
  tmp->status = status;
  tmp->cmd = cmd;
  tmp->next = NULL;
  tmp->prev = list;
  if (list != NULL)
    list->next = tmp;
  else
    return (tmp);
  return (list);
}
