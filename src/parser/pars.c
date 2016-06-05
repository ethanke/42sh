/*
** pars.c for parser in /Users/leandr_g/Documents/Shared folder/42SH/src/parser/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Jun  5 01:18:10 2016 Gaëtan Léandre
** Last update Sun Jun  5 02:10:48 2016 Gaëtan Léandre
*/

#include		"main.h"

int			malloc_size_count(t_pile *pile)
{
  int			size;
  t_pile	*tmp;

  tmp = pile;
  size = 0;
  while (tmp != NULL)
    {
      size++;
      tmp = tmp->next;
    }
  return (size + 1);
}

t_cmd			*end_parsing(t_parser *parser)
{
  t_cmd			*cmd;
  t_cmd			tmp;
  t_pile		*pile;
  int			i;

  i = 0;
  pile = parser->pile->next;
  cmd = init_list_cmd();
  if ((tmp.cmd = malloc(sizeof(char *) * malloc_size_count(pile) + 2)) == NULL)
    return (0);
  while (pile != NULL)
    {
      tmp.token = 0;
      if (pile->token == SEP)
	{
	  tmp.token = get_sep(parser, pile->content);
	  tmp.cmd[i] = 0;
	  add_node_cmd(cmd, tmp.cmd, tmp.token);
	  i = 0;
	  free(tmp.cmd);
	  if ((tmp.cmd = malloc(sizeof(char *) * malloc_size_count(pile) + 1)) == NULL)
	    return (0);
	}
      else
	{
	  tmp.cmd[i] = my_strdup(pile->content);
	  i++;
	}
      pile = pile->next;
    }
  add_node_cmd(cmd, tmp.cmd, tmp.token);
  return (cmd);
}

t_cmd			*get_parse(char *str, t_parser *parser)
{
  char			*tmp;
  char			**table;
  t_cmd			*cmd;

  if ((tmp = pre_parse(str, parser)) == NULL)
    return (NULL);
  if ((table = str_to_wordtable(tmp, "  \t\n")) == NULL)
    return (NULL);
  if ((start_parsing(table, parser)) == -1)
    return (NULL);
  if ((cmd = end_parsing(parser)) == NULL)
    return (NULL);
  return (cmd);
}

char			*get_path(char **env)
{
  int			i;

  i = -1;
  while (env[++i])
    {
      if (my_strncmp(env[i], "PATH=", 5) == 0)
	return (env[i]);
    }
  return (NULL);
}
