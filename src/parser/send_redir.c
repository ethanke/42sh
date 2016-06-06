/*
** send_redir.c for parser in /Users/leandr_g/Documents/Shared folder/42SH/src/parser/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Jun  5 02:11:25 2016 Gaëtan Léandre
** Last update Mon Jun  6 05:53:43 2016 Gaëtan Léandre
*/

#include		"main.h"

int			what_redir(char **redir)
{
  int			one;
  int			tmp;
  int			i;

  one = 0;
  i = 0;
  while (redir[i])
    {
      tmp = 0;
      if (my_strcmp(redir[i], ">") == 1)
	tmp = 1;
      else if (my_strcmp(redir[i], ">>") == 1)
  	tmp = 2;
      else if (my_strcmp(redir[i], "<") == 1)
  	tmp = 3;
      else if (my_strcmp(redir[i], "<<") == 1)
  	tmp = 4;
      if (one == 0)
	one = tmp;
      else if (tmp != 0)
	return (-1);
      i++;
    }
  return (one);
}

int			my_tablestrlen(char **table)
{
  int			i;

  i = 0;
  while (table[i])
    i++;
  return (i);
}

char			**take_start(char **cmd)
{
  char			**result;
  int			size;
  int			i;

  size = my_tablestrlen(cmd);
  if (my_strcmp(cmd[size - 1], ">") == 0
      && my_strcmp(cmd[size - 1], ">>") == 0
      && my_strcmp(cmd[size - 1], "<") == 0
      && my_strcmp(cmd[size - 1], "<<") == 0)
    size -= 1;
  if ((result = malloc(sizeof(char *) * size)) == NULL)
    return (NULL);
  i = 0;
  size = -1;
  while (cmd[++size])
    {
      if (my_strcmp(cmd[size], ">") || my_strcmp(cmd[size], ">>")
          || my_strcmp(cmd[size], "<") || my_strcmp(cmd[size], "<<"))
	size += (cmd[size + 1] == NULL) ? 0 : 1;
      else
	result[i++] = cmd[size];
    }
  result[i] = NULL;
  return (result);
}

char			*take_end(char **cmd)
{
  int			i;

  i = 0;
  while (cmd[i])
    {
      if (my_strcmp(cmd[i], ">") || my_strcmp(cmd[i], ">>")
	  || my_strcmp(cmd[i], "<") || my_strcmp(cmd[i], "<<"))
	return (cmd[i + 1]);
      i++;
    }
  return (NULL);
}

int			exec_redir(char **cmd, t_dlist *dlist)
{
  int			pos;
  int			result;
  char			**start;
  char			*end;

  pos = what_redir(cmd);
  result = 0;
  if (pos < 0)
    {
      my_printf(2, "Ambiguous output redirect.\n");
      return (0);
    }
  else if (pos == 0)
    {
      return (make_command(cmd, dlist));
    }
  else
    {
      start = take_start(cmd);
      end = take_end(cmd);
      (pos == 1 ? (result = right_redir(start, end, dlist)) :
       (pos == 2 ? (result = dright_redir(start, end, dlist)) :
	(pos == 3 ? (result = left_redir(start, end, dlist)) :
	 (result = dleft_redir(start, end, dlist)))));
      if (start != NULL)
	free(start);
    }
   return (result);
}

void			send_cmd(t_cmd *cmd, t_dlist *dlist)
{
  t_cmd			*tmp;
  int			result;

  result = 1;
  tmp = cmd == NULL ? cmd : cmd->next;
  while (tmp != NULL)
    {
	  if (tmp->token == PI)
	    {
	      result = make_pipe(tmp, dlist);
	      while (tmp && tmp->token == PI)
		tmp = tmp->next;
	    }
	  else if (tmp->prev->cmd == NULL || (tmp->prev->token == ET && result == 0))
	    result = exec_redir(tmp->cmd, dlist);
	  else if (tmp->prev->token == OU && result == 1)
	    result = exec_redir(tmp->cmd, dlist);
	  else if (tmp->prev->token == PV)
	    result = exec_redir(tmp->cmd, dlist);
	  tmp = tmp->next;
    }
}
