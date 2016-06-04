/*
** main.c for  in /home/kerdel_e/Shared/42sh/parser
**
** Made by Kerdelhue Ethan
** Login   <kerdel_e@epitech.net>
**
** Started on  Wed May 25 07:06:35 2016 Kerdelhue Ethan
** Last update Sat Jun  4 12:31:23 2016 Ethan Kerdelhue
*/

#include		"parser.h"

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strdup(char *str)
{
  char	*s;

  if ((s = malloc(my_strlen(str) + 1)) == 0)
    return (0);
  my_strcpy(s, str);
  return (s);
}

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

int		print_list(t_cmd *pile)
{
  t_cmd		*tmp;

  tmp = pile;
  while (tmp)
    {
      printf(" TOKEN : %c\n", tmp->token + 48);
      puts("TAB : ");
      print_tab(tmp->cmd);
      tmp = tmp->next;
    }
  return (0);
}

int		get_sep(t_parser *parser, char *str)
{
  int		i;

  i = 0;
  while (parser->sep[i])
    {
      if (my_strcmp(parser->sep[i], str) == 0)
	return (i);
      i++;
    }
  if (my_strcmp("|", str) == 0)
    return (PI);
  return (-1);
}

int		get_nb_sep(t_pile *pile)
{
  int		size;
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

int		malloc_size_count(t_pile *pile)
{
  int		size;
  t_pile	*tmp;

  tmp = pile;
  size = 0;
  while (tmp != NULL)
    {
      size++;
      tmp = tmp->next;
    }
  return (size + 1);
}

int		end_parsing(t_parser *parser)
{
  t_cmd		*cmd;
  t_cmd		tmp;
  t_pile	*pile;
  int		i;

  i = 0;
  pile = parser->pile->next;
  cmd = init_list_cmd();
  printf("MALLOC SIZE : %d\n", malloc_size_count(pile));
  if ((tmp.cmd = malloc(sizeof(char *) * get_nb_sep(pile) + 2 * sizeof(void *))) == NULL)
    return (0);
  while (pile != NULL)
    {
      tmp.token = 0;
      if (pile->token == SEP)
	{
	  tmp.token = get_sep(parser, pile->content);
	  add_node_cmd(cmd, tmp.cmd, tmp.token);
	  i = 0;
	  free(tmp.cmd);
	  if ((tmp.cmd = malloc(sizeof(char *) * get_nb_sep(pile) + 1)) == NULL)
	    return (0);
	}
      else
	{
	  tmp.cmd[i] = my_strdup(pile->content);
	  i++;
	}
      puts(tmp.cmd[i]);
      pile = pile->next;
    }
  print_list(cmd);
  return (0);
}

int		get_parse(char *str, t_parser *parser)
{
  char		*tmp;
  char		**tab;
  t_cmd		**cmd;

  tmp = pre_parse(str, parser);
  tab = str_to_wordtab(tmp, "  \t\n");
  start_parsing(tab, parser);
  printf(" CMD TREATMENT ----> ");
  end_parsing(parser);
  (void) tab;
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
