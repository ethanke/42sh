/*
** opt.c for  in /Users/ethankerdelhue/Documents/Shared/42sh/parser/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon May 30 17:13:16 2016 Ethan Kerdelhue
** Last update Thu Jun  2 06:29:35 2016 Ethan Kerdelhue
*/

#include	"parser.h"

int		isopt(char *str, t_parser *parser)
{
  int		i;

  i = 0;
  while (parser->opt[i])
    {
      if (my_strncmp(parser->opt[i], str, my_strlen(parser->opt[i])) == 0
	  && my_strncmp(str, "||", 2) != 0)
	return (1);
      i++;
    }
  return (0);
}

int		opt_parsing(char **tab, t_parser *parser, int i, char *flag)
{
  if (isopt(tab[i], parser) == 1)
    {
      if (add_node(parser->pile, OPE, tab[i]) == -1)
	return (-1);
      *flag = 0;
    }
  return (0);
}

char			**load_opt()
{
  char			**tab;

  if ((tab = malloc(sizeof(char *) * 6)) == NULL)
    return (NULL);
  tab[0] = "|";
  tab[1] = "<<";
  tab[2] = ">>";
  tab[3] = "<";
  tab[4] = ">";
  tab[5] = NULL;
  return (tab);
}
