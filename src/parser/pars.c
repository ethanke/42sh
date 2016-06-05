/*
** pars.c for parser in /Users/leandr_g/Documents/Shared folder/42SH/src/parser/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Jun  5 01:18:10 2016 Gaëtan Léandre
** Last update Sun Jun  5 05:32:07 2016 Ethan Kerdelhue
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

int			list_len(t_cmd *cmd)
{
  int			i;
  t_cmd			*tmp;

  tmp = cmd;
  i = 0;
  while (tmp)
    {
      i++;
      tmp = tmp->next;
    }
  printf("LIST LEN : %d", i);
  return (0);
}

void			list_print(t_pile *pile)
{
  t_pile 		*tmp;

  tmp = pile;
  while (tmp)
    {
      printf("C: %s T: %d\n", pile->content, pile->token);
      tmp = tmp->next;
    }
}

t_cmd			*end_parsing(t_parser *parser)
{
  t_cmd			*cmd;
  t_cmd			tmp;
  t_pile		*pile;
  int			i;

  i = 0;
  pile = parser->pile->next;
  if ((cmd = init_list_cmd()) == NULL)
    return (NULL);
  if ((tmp.cmd = malloc(sizeof(char *) * malloc_size_count(pile) + 2)) == NULL)
    return (NULL);
  while (pile != NULL)
    {
      tmp.token = 0;
      if (pile->token == SEP)
	{
	  tmp.token = get_sep(parser, pile->content);
	  tmp.cmd[i] = NULL;
	  if (add_node_cmd(cmd, tmp.cmd, tmp.token) == -1)
	    return (NULL);
	  i = 0;
	  free(tmp.cmd);
	  if ((tmp.cmd = malloc(sizeof(char *) * malloc_size_count(pile) + 1)) == NULL)
	    return (NULL);
	}
      else
	{
	  if ((tmp.cmd[i] = my_strdup(pile->content)) == NULL)
	    return (NULL);
	  i++;
	}
      pile = pile->next;
    }
  tmp.cmd[i] = NULL;
  if (add_node_cmd(cmd, tmp.cmd, tmp.token) == -1)
    return (NULL);
  return (cmd);
}

int			tabr(char **ta)
{
  int			i;

  i = -1;
  while (ta[++i])
    puts(ta[i]);
  return (0);
}

int			get_parse(char *str, t_parser *parser)
{
  char			*tmp;
  char			**table;

  if ((tmp = pre_parse(str, parser)) == NULL)
    return (-1);
  if ((table = str_to_wordtable(tmp, "  \t\n")) == NULL)
    return (-1);
  if ((start_parsing(table, parser)) == -1)
    return (-1);
  if ((parser->cmd = end_parsing(parser)) == NULL)
    return (-1);
  return (0);
}

t_cmd			*parsing(char *str, char **path)
{
  t_parser		parser;

  if ((parser.pile = init_list()) == NULL)
    return (NULL);
  if ((parser.opt = load_opt()) == NULL)
    return (NULL);
  if ((parser.sep = load_sep()) == NULL)
    return (NULL);
  if ((parser.path = path) == NULL)
    return (NULL);
  if (get_parse(str, &parser) == -1)
    return (NULL);
  return (parser.cmd);
}
