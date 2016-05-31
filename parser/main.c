/*
** main.c for  in /home/kerdel_e/Shared/42sh/parser
**
** Made by Kerdelhue Ethan
** Login   <kerdel_e@epitech.net>
**
** Started on  Wed May 25 07:06:35 2016 Kerdelhue Ethan
** Last update Tue May 31 16:35:19 2016 Ethan Kerdelhue
*/

#include		"parser.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char	*my_strcat_wm(char *s, char *s2)
{
  int	i;
  int	j;

  i = my_strlen(s);
  j = 0;
  while (s2[j])
    s[i++] = s2[j++];
  s[i] = '\0';
  return (s);
}

int			my_strncmp(char *s1, char *s2, int n)
{
  while (n && *s1 && *s2 && *s1 == *s2)
    {
      s1++;
      s2++;
      n--;
    }
  if (!n)
    return (n);
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

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
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

int		cmd_parsing(char **tab, t_parser *parser, int i, char *flag)
{
  if (*flag == 1 && iscmd(tab[i], parser) == 1)
    {
      if (add_node(parser->pile, OPT, tab[i]) == -1)
	return (-1);
    }
  else if (iscmd(tab[i], parser) == 1)
    {
      if (add_node(parser->pile, CMD, tab[i]) == -1)
	return (-1);
      *flag = 1;
    }
  else if (*flag == 1 && iscmd(tab[i], parser) == 0)
    {
      if (add_node(parser->pile, OPT, tab[i]) == -1)
	return (-1);
    }
  return (0);
}

int		start_parsing(char **tab, t_parser *parser)
{
  int		i;
  char		flag;

  i = 0;
  flag = 0;
  while (tab[i])
    {
      if ((opt_parsing(tab ,parser, i, &flag)) == -1)
	return (-1);
      if ((sep_parsing(tab, parser, i, &flag)) == -1)
	return (-1);
      if ((cmd_parsing(tab, parser, i, &flag)) == -1)
	return (-1);
      i++;
    }
  return (0);
}

char		*pre_parse(char *str, t_parser *parser)
{
  char		*new;

  new = epur_string(str);
  new = epur_sep(new, parser->sep, -1, 0);
  printf("%s\n", str);
  /* new = epur_opt(new, parser->opt, -1, 0); */
  return (new);
}

int		get_parse(char *str, t_parser *parser)
{
  char		*tmp;
  char		**tab;
  int 		i;

  i = 0;
  tmp = pre_parse(str, parser);
  puts(tmp);
  tab = str_to_wordtab(tmp, " \t\n");

  printf("priting word tab of cmd separated by ' '\n");
  while (tab[i])
    printf("%s\n", tab[i++]);
  printf("done\n");
  start_parsing(tab, parser);
  return (0);
}

char		*get_path(char **env)
{
  int		i;

  i = -1;
  while (env[++i])
    {
      if (my_strncmp(env[i], "PATH=", 5) == 0)
	return (env[i]);
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

void          	clear_list(t_pile *list)
{
 t_pile         *tmp;
 t_pile         *tmpnext;

 tmp = list;
 while (tmp != NULL)
   {
     tmpnext = tmp->next;
     free(tmp);
     tmp = tmpnext;
   }
}

int		free_for_all(char **tab)
{
  int		i;

  i = -1;
  while (tab[++i])
    free(tab[i]);
  free(tab);
  return (0);
}

int		main(int ac, char **av, char **env)
{
  t_parser	*parser;
  char		*str;

  (void) ac;
  (void) av;
  parser = malloc(sizeof(t_parser));
  parser->sep = load_sep();
  parser->opt = load_opt();
  parser->pile = init_list();
  parser->path = str_to_wordtab(get_path(env), ":");
  while (1)
    {
      parser->pile = init_list();
      my_putstr("$>");
      str = get_next_line(0);
      get_parse(str, parser);
      print_list(parser->pile);
      clear_list(parser->pile);
      my_putstr("\n");
      free(str);
    }
  free_for_all(parser->sep);
  free_for_all(parser->opt);
  return (0);
}
