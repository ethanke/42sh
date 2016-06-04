/*
** link_list.c for  in /home/kerdel_e/Shared/42sh/parser
**
** Made by Kerdelhue Ethan
** Login   <kerdel_e@epitech.net>
**
** Started on  Wed Jun  1 22:08:43 2016 Kerdelhue Ethan
** Last update Fri Jun  3 23:57:23 2016 Ethan Kerdelhue
*/

#include		"parser.h"

int			add_node(t_pile *pile, char token, char *content)
{
  t_pile		*tmp;
  t_pile		*new;

  if ((new = malloc(sizeof(t_pile))) == NULL)
    return (-1);
  tmp = pile;
  while (tmp->next)
    tmp = tmp->next;
  new->token = token;
  new->content = content;
  new->next = NULL;
  new->prev = tmp;
  tmp->next = new;
  return (0);
}

t_pile			*init_list()
{
  t_pile		*tmp;

  if ((tmp = malloc(sizeof(t_pile))) == NULL)
    return (0);
  tmp->token = SKI;
  tmp->content = "NULL";
  tmp->next = NULL;
  tmp->prev = NULL;
  return (tmp);
}

int			add_node_cmd(t_cmd_list *cmd,
					  char **tab,
					  char token)
{
  t_cmd_list			*tmp;
  t_cmd_list			*new;

  if ((new = malloc(sizeof(t_cmd_list))) == NULL)
    return (-1);
  tmp = cmd;
  while (tmp->next)
    tmp = tmp->next;
  new->token = token;
  new->cmd = cmd;
  new->prev = tmp;
  tmp->next = new;
  return (0);
}

t_cmd_list			*init_list_cmd()
{
  t_cmd_list			*tmp;

  if ((tmp = malloc(sizeof(t_cmd_list))) == NULL)
    return (0);
  tmp->token = SKI;
  tmp->cmd = NULL;
  tmp->next = NULL;
  tmp->prev = NULL;
  return (tmp);
}
