/*
** sep.c for  in /Users/ethankerdelhue/Documents/Shared/42sh/parser/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon May 30 17:17:39 2016 Ethan Kerdelhue
** Last update Tue May 31 06:36:57 2016 Ethan Kerdelhue
*/

#include	"parser.h"

int		issep(char *str, t_parser *parser)
{
  int		i;

  i = 0;
  while (parser->sep[i])
    {
      if (my_strncmp(parser->sep[i], str, my_strlen(parser->sep[i])) == 0)
	return (1);
      i++;
    }
  return (0);
}

int		sep_parsing(char **tab, t_parser *parser, int i, char *flag)
{
  if (issep(tab[i], parser) == 1)
    {
      if (add_node(parser->pile, SEP, tab[i]) == -1)
	  return (-1);
      *flag = 0;
    }
  return (0);
}

char			**load_sep()
{
  char			**tab;

  if ((tab = malloc(sizeof(char *) * 4)) == NULL)
    return (NULL);
  tab[0] = ";";
  tab[1] = "||";
  tab[2] = "&&";
  tab[3] = NULL;
  return (tab);
}
