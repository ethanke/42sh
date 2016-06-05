/*
** cmd.c for  in /Users/ethankerdelhue/Documents/Shared/42sh/parser/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed Jun  1 22:13:03 2016 Ethan Kerdelhue
** Last update Sun Jun  5 05:50:50 2016 Ethan Kerdelhue
*/

#include	"parser.h"

int		iscmd(char *str, t_parser *parser)
{
  int		i;
  char		*tmp;

  i = 0;
  if (access(str, F_OK) == 0)
    return (1);
  else
    {
      str = my_strcat("/", str);
      while (parser->path[i])
	{
	  tmp = my_strcat(parser->path[i], str);
	  if (access(tmp, F_OK) == 0)
	    return (1);
	  i++;
	}
      free(str);
      free(tmp);
    }
  return (0);
}
/*
int		cmd_parsing(char **table, t_parser *parser, int i, char *flag)
{
  if (*flag == 1)
    {
      if (add_node(parser->pile, OPT, table[i]) == -1)
	return (-1);
    }
  else if (iscmd(table[i], parser) == 1)
    {
      if (add_node(parser->pile, CMD, table[i]) == -1)
	return (-1);
      *flag = 1;
    }
  return (0);
}
*/
int		check_last(t_pile *pile)
{
  t_pile	*tmp;

  tmp = pile;
  while (tmp->next)
    tmp = tmp->next;
  if (tmp)
    return (((my_strcmp(tmp->content, "<") == 0) ? (1) :
	     (my_strcmp(tmp->content, ">") == 0) ? (1) :
	     (my_strcmp(tmp->content, "<<") == 0) ? (1) :
	     (my_strcmp(tmp->content, ">>") == 0) ? (1) : (0)));
  return (0);
}
