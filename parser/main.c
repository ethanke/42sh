/*
** main.c for  in /home/kerdel_e/Shared/42sh/parser
**
** Made by Kerdelhue Ethan
** Login   <kerdel_e@epitech.net>
**
** Started on  Wed May 25 07:06:35 2016 Kerdelhue Ethan
** Last update Sat Jun  4 02:53:59 2016 Ethan Kerdelhue
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

int		my_strcmp(char *s1, char *s2)
{
  return ((my_strlen(s1) != my_strlen(s2)) ? (-1)
	  : (my_strncmp(s1, s2, my_strlen(s1))));
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

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int		start_parsing(char **tab, t_parser *parser)
{
  int		i;
  char		flag;

  i = 0;
  flag = 0;
  while (tab[i])
    {
      if ((special_case(tab, parser, i, &flag)) == -1)
	return (-1);
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
  new = epur_opt(new, parser->opt, -1, 0);
  return (new);
}

int		tablen(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

int		print_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      puts(tab[i]);
      i++;
    }
  return (0);
}

int		add_line_tab(char **tab, char *line)
{
  int		i;
  char		**new;

  if ((new = malloc(tablen(tab) + 2)) == NULL)
    return (-1);
  while (tab[i])
    {
      new[i] = my_strdup(tab[i]);
      i++;
    }
  new[i] = my_strdup(line);
  free(line);
  free_for_all(tab);
  return (new);
}

int		end_parsing(t_parser *parser)
{
  t_cmd		*cmd;
  t_cmd		tmp;
  t_pile	*pile;
  char		flag;

  pile = parser->pile;
  cmd = init_list_cmd();
  (void) cmd;
  while (pile != NULL)
    {
      tmp.token = -1;
      if (pile->token == SEP)
	{
	  tmp.token = SEP;
	  add_node_cmd(cmd, tmp.cmd, tmp.token);
	}

      add_node_cmd(cmd, tmp.cmd, tmp.token);
      pile = pile->next;
    }
  return (0);
}

int		get_parse(char *str, t_parser *parser)
{
  char		*tmp;
  char		**tab;
  int 		i;
  t_cmd		**cmd;

  i = 0;
  tmp = pre_parse(str, parser);
  tab = str_to_wordtab(tmp, " \t\n");
  start_parsing(tab, parser);
  puts(" CMD TREATMENT ----> ");
  end_parsing(parser);
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
      clear_list(parser->pile);
      my_putstr("\n");
      free(str);
    }
  free_for_all(parser->sep);
  free_for_all(parser->opt);
  return (0);
}
