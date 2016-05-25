/*
** main.c for  in /home/kerdel_e/Shared/42sh/parser
**
** Made by Kerdelhue Ethan
** Login   <kerdel_e@epitech.net>
**
** Started on  Wed May 25 07:06:35 2016 Kerdelhue Ethan
** Last update Wed May 25 16:57:39 2016 Ethan Kerdelhue
*/

#include		"parser.h"

int			my_strncmp(char *s1, char *s2, int n)
{
  while (n && *s1 && *s2 && *s1 == *s2)
    {
      s1++;
      s2++;
      n--;
    }
  if (!n)
    {
      return (n);
    }
  return (*s1 - *s2);
}

int			add_node(t_pile *pile, char token, char *content)
{
  t_pile		*tmp;
  t_pile		*new;

  if ((new = malloc(sizeof(t_pile))) == NULL)
    return (-1);
  tmp = pile;
  while (tmp->next)
    tmp = tmp->next;
  new->token = token;
  new->content = content;
  new->next = NULL;
  new->prev = tmp;
  tmp->next = new;
  return (0);
}

t_pile			*init_list()
{
  t_pile		*tmp;

  if ((tmp = malloc(sizeof(t_pile))) == NULL)
    return (0);
  tmp->token = SKI;
  tmp->content = "NULL";
  tmp->next = NULL;
  tmp->prev = NULL;
  return (tmp);
}

int		my_strlen(char *str)
{
  int		i;

   i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

char		*epur_string(char *str)
{
  char		*new;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if ((new = malloc(my_strlen(str) + 1)) == NULL)
    return (0);
  while (str[i] == ' ')
    i++;
  while (str[i])
    {
      if (str[i] != ' ' || (str[i] == ' ' && str[i - 1] != ' '))
	{
	  new[j] = str[i];
	  j++;
	}
      i++;
    }
  new[j] = 0;
  return (new);
}

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
    }
  return (0);
}

int		start_parsing(char **tab, t_parser *parser)
{
  int		i;
  char		flag;

  i = 0;
  flag = 1;
  while (tab[i])
    {
      if (iscmd(tab[i], parser) == 1)
	{
	  add_node(parser->pile, CMD, tab[i]);
	  flag = 1;
	}
      else if (flag == 1 && iscmd(tab[i], parser) == 0)
	add_node(parser->pile, OPT, tab[i]);
      else
	{
	  if (flag == 1 && iscmd(tab[i], parser) == 1)
	    add_node(parser->pile, OPT, tab[i]);
	}
      i++;
    }
  return (0);
}

int		get_parse(char *str, t_parser *parser)
{
  char		*tmp;
  char		**tab;

  tmp = epur_string(str);
  tab = my_str_to_wordtab(tmp, " \t\n");
  start_parsing(tab, parser);
  return (0);
}

char		*get_path(char **env)
{
  int		i;

  i = 0;
  while (env[i])
    {
      if (my_strncmp(env[i], "PATH=", 5) == 0)
	return (env[i]);
      i++;
    }
  return (NULL);
}

int		print_list(t_pile *pile)
{
  t_pile	*tmp;

  tmp = pile;
  while (tmp)
    {
      printf("%c - %s\n", tmp->token + 48, tmp->content);
      tmp = tmp->next;
    }
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_parser	*parser;
  char		*str;

  (void) ac;
  (void) av;
  parser = malloc(sizeof(t_parser));
  parser->pile = init_list();
  parser->path = my_str_to_wordtab(get_path(env), ":");
  while (1)
    {
      my_putstr("$>");
      str = get_next_line(0);
      get_parse(str, parser);
      print_list(parser->pile);
      my_putstr("\n");
      free(str);
    }
  return (0);
}
