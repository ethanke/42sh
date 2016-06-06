/*
** endparsing.c for 42sh in /Users/leandr_g/Documents/Shared folder/42SH/src/parser/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Jun  6 22:38:38 2016 Gaëtan Léandre
** Last update Mon Jun  6 23:13:46 2016 Gaëtan Léandre
*/

#include	"main.h"

char		*my_strcheat(char *str, int *flag, int *i)
{
  char		*result;

  result = my_strdup(str);
  *flag = 0;
  (*i)++;
  return (result);
}

t_cmd		*make_pile(t_pile *pile, t_cmd *cmd, t_parser *parser, t_cmd *tmp)
{
  int		flag;
  int		i;
  int		j;

  i = 0;
  flag = 0;
  j = 0;
  while (pile != NULL)
    {
      tmp[j].token = 0;
      if (pile->token == SEP || (my_strcmp(pile->content, "|") == 1))
	{
	  tmp[j].token = get_sep(parser, pile->content);
	  tmp[j].cmd[i] = NULL;
	  if (add_node_cmd(cmd, tmp[j].cmd, tmp[j].token) == -1)
	    return (NULL);
	  (j)++;
	  i = 0;
	  if ((tmp[j].cmd = malloc(sizeof(char *) *
				   (malloc_size_count(pile) + 1))) == NULL)
	    return (NULL);
	  flag = 1;
	}
      else
	if ((tmp[j].cmd[i] = my_strcheat(pile->content, &flag, &i)) == NULL)
	   return (NULL);
      pile = pile->next;
    }
    tmp[j].cmd[i] = NULL;
    push_t_cmd(cmd, tmp, flag, j);
    return (cmd);
}
