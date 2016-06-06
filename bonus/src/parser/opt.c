/*
** opt.c for  in /Users/ethankerdelhue/Documents/Shared/42sh/parser/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon May 30 17:13:16 2016 Ethan Kerdelhue
** Last update Mon Jun  6 02:44:09 2016 Ethan Kerdelhue
*/

#include	"main.h"

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

char			**load_opt()
{
  char			**table;

  if ((table = malloc(sizeof(char *) * 6)) == NULL)
    return (NULL);
  table[0] = "|";
  table[1] = "<<";
  table[2] = ">>";
  table[3] = "<";
  table[4] = ">";
  table[5] = NULL;
  return (table);
}
