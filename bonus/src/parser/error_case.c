/*
** error_case.c for  in /Users/ethankerdelhue/Documents/Shared/42sh/src/parser/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Jun  6 00:57:46 2016 Ethan Kerdelhue
** Last update Mon Jun  6 04:14:20 2016 Ethan Kerdelhue
*/

#include		"parser.h"

int			my_perror(char *str)
{
  write(2, str, my_strlen(str));
  return (-1);
}

int			pi_case(t_cmd *tmp)
{
  if ((tmp->token == PI) && (tablen(tmp->cmd) == 0))
    return (my_perror("Invalid null command.\n"));
  else if ((tmp->token == PI) && tmp->next == NULL)
    return (my_perror("Invalid null command.\n"));
  return (0);
}

int			ou_case(t_cmd *tmp)
{
  if ((tmp->token == OU) && (tablen(tmp->cmd) == 0))
    return (my_perror("Invalid null command.\n"));
  else if ((tmp->token == OU) && tmp->next == NULL)
    return (my_perror("Invalid null command.\n"));
  return (0);
}

int			error_case(t_cmd *cmd)
{
  t_cmd			*tmp;

  tmp = cmd;
  while (tmp)
    {
      if (ou_case(tmp) == -1)
	return (-1);
      if (pi_case(tmp) == -1)
	return (-1);
      tmp = tmp->next;
    }
  return (0);
}
