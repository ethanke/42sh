/*
** main.c for  in /home/kerdel_e/Shared/42sh/parser
**
** Made by Kerdelhue Ethan
** Login   <kerdel_e@epitech.net>
**
** Started on  Wed May 25 07:06:35 2016 Kerdelhue Ethan
** Last update Thu May 26 06:01:19 2016 Ethan Kerdelhue
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

static char 			*my_strcat_custom(char *dest, char *src)
{
  int len;
  int i;

  len = my_strlen(dest);
  i = 0;
  while (src[i])
    {
      dest[len + i] = src[i];
      i = i + 1;
    }
  return (dest);
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

int		issep(char *str, t_parser *parser)
{
  int		i;

  i = 0;
  while (parser->sep[i])
    {
      if (my_strncmp(parser->sep[i], str, my_strlen(str)) == 0)
	return (1);
      i++;
    }
  return (0);
}

int		isopt(char *str, t_parser *parser)
{
  int		i;

  i = 0;
  while (parser->opt[i])
    {
      if (my_strncmp(parser->opt[i], str, my_strlen(str)) == 0)
	return (1);
      i++;
    }
  return (0);
}

int		opt_parsing(char **tab, t_parser *parser, int i, char *flag)
{
  if (isopt(tab[i], parser) == 1)
    {
      if (add_node(parser->pile, OPT, tab[i]) == -1)
	return (-1);
      *flag = 0;
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

int		count_size_sep(char *str, char **sep)
{
  int		i;
  int		j;
  int		size;

  i = -1;
  j = 0;
  size = my_strlen(str);
  while (str[++i])
    {
      j = 0;
      while (sep[j])
	{
	  if (my_strncmp(&str[i], sep[j], my_strlen(sep[j])) == 0)
	    size += 2;
	  j++;
	}
    }
  return (size);
}

char		*epur_sep(char *str, char **delim)
{
  int		i;
  int		j;
  int		k;
  char		*new;
  char		flag;

  i = -1;
  k = 0;
  if ((new = malloc(count_size_sep(str, delim) + 1)) == NULL)
    return (NULL);
  while (str[++i])
    {
      flag = 1;
      j = -1;
      while (delim[++j])
	{
	  if (my_strncmp(str + i, delim[j], my_strlen(delim[j])) == 0)
	    {
	      new[k] = '\0';
	      new = my_strcat(new, my_strcat(" ", my_strcat(delim[j], " ")));
	      k += my_strlen(delim[j]) + 2;
	      i += my_strlen(delim[j]) - 1;
	      flag = 0;
	    }
	}
      if (flag)
	new[k++] = str[i];
    }
  new[k] = 0;
  return (new);
}

char		*pre_parse(char *str, t_parser *parser)
{
  char		*new;

  new = epur_string(str);
  new = epur_sep(new, parser->sep);
  new = epur_sep(new, parser->opt);
  return (new);
}

int		get_parse(char *str, t_parser *parser)
{
  char		*tmp;
  char		**tab;

  tmp = pre_parse(str, parser);
  tab = str_to_wordtab(tmp, " \t\n");

  printf("\npriting word tab of cmd separated by ' '\n");
  int i = 0;
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

void                    clear_list(t_pile *list)
{
 t_pile                *tmp;
 t_pile                *tmpnext;

 tmp = list;
 while (tmp != NULL)
   {
     tmpnext = tmp->next;
     free(tmp);
     tmp = tmpnext;
   }
 return;
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

int			free_for_all(char **tab)
{
  int			i;

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
