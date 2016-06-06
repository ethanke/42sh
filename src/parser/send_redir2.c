/*
** send_redir2.c for  in /home/sousa_v/rendu/psu/42sh
** 
** Made by victor sousa
** Login   <sousa_v@epitech.net>
** 
** Started on  Mon Jun  6 22:04:48 2016 victor sousa
** Last update Mon Jun  6 23:00:18 2016 victor sousa
*/

#include	"main.h"

int                     send_cmd(t_cmd *cmd, t_dlist *dlist)
{
  t_cmd                 *tmp;
  int                   result;

  result = 0;
  tmp = cmd == NULL ? cmd : cmd->next;
  while (tmp != NULL)
    {
      if (tmp->token == PI)
	{
	  result = make_pipe(tmp, dlist);
	  while (tmp && tmp->token == PI)
	    tmp = tmp->next;
	}
      else if (tmp->prev->cmd == NULL ||
	       (tmp->prev->token == ET && result == 0))
	result = exec_redir(tmp->cmd, dlist);
      else if (tmp->prev->token == OU && result != 0)
	result = exec_redir(tmp->cmd, dlist);
      else if (tmp->prev->token == PV)
	result = exec_redir(tmp->cmd, dlist);
      tmp = tmp->next;
    }
  return (result);
}
