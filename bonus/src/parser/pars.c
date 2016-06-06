/*
** pars.c for  in /home/kerdel_e/Shared/42sh/src/parser
**
** Made by Kerdelhue Ethan
** Login   <kerdel_e@epitech.net>
**
** Started on  Mon Jun  6 21:19:59 2016 Kerdelhue Ethan
** Last update Mon Jun  6 23:14:47 2016 Gaëtan Léandre
*/

#include		"main.h"

int			push_t_cmd(t_cmd *cmd, t_cmd *tmp, char flag, int j)
{
  if (flag == 0)
    {
      if (add_node_cmd(cmd, make_glob(tmp[j].cmd), tmp[j].token) == -1)
	return (-1);
    }
  return (0);
}

t_cmd			*end_parsing(t_parser *parser, int j)
{
  t_cmd			*cmd;
  t_cmd			*tmp;
  t_pile		*pile;

  pile = parser->pile->next;
  if ((cmd = init_list_cmd()) == NULL || (tmp = malloc(sizeof(t_cmd)
			   * (malloc_size_count(pile) + 2))) == NULL
      || (tmp[j].cmd = malloc(sizeof(char *)
			      * malloc_size_count(pile) + 2)) == NULL)
    return (NULL);
  return (make_pile(pile, cmd, parser, tmp));
}

int			get_parse(char *str, t_parser *parser, int i, int j)
{
  char			*tmp;
  char			**table;

  if ((tmp = pre_parse(str, parser)) == NULL)
    return (-1);
  if ((table = str_to_wordtable(tmp, " \t\n")) == NULL)
    return (-1);
  while (table[i])
    {
      j = 0;
      while (table[i][j])
	{
	  if (table[i][j] < 0)
	    table[i][j] = - table[i][j];
	  j++;
	}
      i++;
    }
  if ((start_parsing(table, parser)) == -1)
    return (-1);
  if ((parser->cmd = end_parsing(parser, 0)) == NULL)
    return (-1);
  return (0);
}

t_cmd			*parsing(char *str, char **path)
{
  t_parser		parser;

  (void) path;
  if ((parser.pile = init_list()) == NULL)
    return (NULL);
  if ((parser.opt = load_opt()) == NULL)
    return (NULL);
  if ((parser.sep = load_sep()) == NULL)
    return (NULL);
  if (get_parse(str, &parser, 0, 0) == -1)
    return (NULL);
  if (error_case(parser.cmd) == -1)
    return (NULL);
  return (parser.cmd);
}
