/*
** start_pars.c for parser in /Users/leandr_g/Documents/Shared folder/42SH/src/parser/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Jun  5 01:16:02 2016 Gaëtan Léandre
** Last update Mon Jun  6 03:00:13 2016 Ethan Kerdelhue
*/

#include		"main.h"

int			start_parsing(char **table, t_parser *parser)
{
  int			i;

  i = 0;
  while (table[i])
    {
      if (isopt(table[i], parser) == 1)
	{
	  if ((parser->pile = add_node(parser->pile, OPE, table[i])) == NULL)
	    return (-1);
	}
      else if (issep(table[i], parser) == 1)
	{
	  if ((parser->pile = add_node(parser->pile, SEP, table[i])) == NULL)
	    return (-1);
	}
      else
	{
	  if ((parser->pile = add_node(parser->pile, CMD, table[i])) == NULL)
	    return (-1);
	}
      i++;
    }
  return (0);
}

char			*pre_parse(char *str, t_parser *parser)
{
  char			*new;

  if ((new = epur_string(str)) == NULL)
    return (NULL);
  if ((new = epur_sep(new, parser->sep, -1, 0)) == NULL)
    return (NULL);
  if ((new = epur_opt(new, parser->opt, -1, 0)) == NULL)
    return (NULL);
  return (new);
}

int			tablen(char **table)
{
  int			i;

  i = 0;
  while (table[i])
    i++;
  return (i);
}

int			get_sep(t_parser *parser, char *str)
{
  int			i;

  i = 0;
  while (parser->sep[i])
    {
      if (my_strcmp(parser->sep[i], str) == 1)
	return (i);
      i++;
    }
  if (my_strcmp("|", str) == 1)
    return (PI);
  return (-1);
}

int			get_nb_sep(t_pile *pile)
{
  int			size;
  t_pile	*tmp;

  tmp = pile;
  size = 0;
  while (tmp->next)
    {
      if (tmp->token == SEP)
	size += 1;
      tmp = tmp->next;
    }
  return (size);
}
