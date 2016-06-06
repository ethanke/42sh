/*
** sep.c for  in /Users/ethankerdelhue/Documents/Shared/42sh/parser/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon May 30 17:17:39 2016 Ethan Kerdelhue
** Last update Mon Jun  6 19:12:30 2016 Ethan Kerdelhue
*/

#include	"main.h"

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

char			**load_sep()
{
  char			**table;

  if ((table = malloc(sizeof(char *) * 4)) == NULL)
    return (NULL);
  table[0] = ";";
  table[1] = "||";
  table[2] = "&&";
  table[3] = NULL;
  return (table);
}
