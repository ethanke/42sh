#include		"parser.h"

static int		my_strcmp(char *a, char *b)
{
  int			i;

  i = 0;
  while (a[i] || b[i])
    {
      if (a[i] != b[i])
	return (0);
      i++;
    }
  return (1);
}

int			what_redir(char **redir)
{
  int			one;
  int			tmp;
  int			i;

  one = 0;
  i = -1;
  while (redir[++i])
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
	  || my_strcmp(cmd[i], "<") || my_strcmp(redir[i], "<<"))
	return (cmd[i + 1]);
    }
  return (cmd);
}

int			exec_redir(t_cmd *cmd)
{
  int			pos;
  int			result;
  char			**start;
  char			*end;

  pos = what_redir(cod->table);
  result = 0;
  if (pos < 0)
    //erreur multiples redirections
  else if (pos == 0)
    //result = execution normale
  else
    {
      start = take_start(cmd->table);
      end = take_end(cmd);
      (pos == 1 ? (result = right_redir(start, end)) :
       (pos == 2 ? (result = dright_redif(start, end)) :
	(pos == 3 ? (result = left_redif(start, end)) :
	 (result = dleft_redif(start, end)))));
      if (start != NULL)
	free(start);
    }
   return (result);
}

t_cmd			*send_cmd(t_cmd *cmd)
{
  t_cmd			*tmp;

  tmp = cmd;
  while (tmp != NULL)
    {
      exec_redir(tmp);
      tmp = tmp->next;
    }
}
