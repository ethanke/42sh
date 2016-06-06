/*
** endparsing.c for 42sh in /Users/leandr_g/Documents/Shared folder/42SH/src/parser/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Jun  6 22:38:38 2016 Gaëtan Léandre
** Last update Mon Jun  6 23:22:37 2016 victor sousa
*/

#include	"main.h"

char		*mt(char *str, int *flag, int *i)
{
  char		*result;

  result = my_strdup(str);
  *flag = 0;
  (*i)++;
  return (result);
}

t_cmd		*make_pile(t_pile *pile, t_cmd *cmd, t_parser *parser, t_cmd *tmp)
{
  t_vec		m;

  m.i = 0 + (m.j = 0) * 0 + (m.flag = 0) * 0;
  while (pile != NULL)
    {
      tmp[m.j].token = 0;
      if (pile->token == SEP || (my_strcmp(pile->content, "|") == 1))
	{
	  tmp[m.j].token = get_sep(parser, pile->content);
	  tmp[m.j].cmd[m.i] = NULL;
	  if (add_node_cmd(cmd, tmp[m.j].cmd, tmp[m.j].token) == -1)
	    return (NULL);
	  m.j = m.j + 1 + (m.i = 0) * 0 + (m.flag = 1) * 0;
	  if ((tmp[m.j].cmd = malloc(sizeof(char *) *
				   (malloc_size_count(pile) + 1))) == NULL)
	    return (NULL);
	}
      else
	if ((tmp[m.j].cmd[m.i] = mt(pile->content, &m.flag, &m.i)) == NULL)
	   return (NULL);
      pile = pile->next;
    }
  tmp[m.j].cmd[m.i] = NULL;
  push_t_cmd(cmd, tmp, m.flag, m.j);
  return (cmd);
}
