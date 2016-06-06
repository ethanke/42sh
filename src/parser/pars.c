/*
** pars.c for  in /Users/ethankerdelhue/Documents/Shared/42sh/src/parser/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Jun  6 04:06:14 2016 Ethan Kerdelhue
** Last update Mon Jun  6 17:14:34 2016 Ethan Kerdelhue
*/

#include		"main.h"

char			*my_my_strcat(char *a, char *b)
{
  int			size;
  char			*str;
  int			i;
  int			j;

  size = my_strlen(a) + my_strlen(b) + 2;
  if ((str = malloc(size)) == NULL)
    return (NULL);
  i = 0;
  while (a[i])
    {
      str[i] = a[i];
      i++;
    }
  j = 0;
  while (b[j])
    {
      str[i] = b[j];
      i++;
      j++;
    }
  str[i] = '\0';
  return (str);
}

int			malloc_size_count(t_pile *pile)
{
  int			size;
  t_pile		*tmp;

  tmp = pile;
  size = 0;
  while (tmp != NULL)
    {
      size++;
      tmp = tmp->next;
    }
  return (size + 1);
}

int			list_len(t_cmd *cmd)
{
  int			i;
  t_cmd			*tmp;

  tmp = cmd;
  i = 0;
  while (tmp)
    {
      i++;
      tmp = tmp->next;
    }
  printf("LIST LEN : %d", i);
  return (0);
}

void			list_print(t_pile *pile)
{
  t_pile 		*tmp;

  tmp = pile;
  while (tmp)
    {
      printf("C: %s \n", tmp->content);
      tmp = tmp->next;
    }
}

t_cmd			*end_parsing(t_parser *parser, int i, int j, char flag)
{
  t_cmd			*cmd;
  t_cmd			*tmp;
  t_pile		*pile;


  pile = parser->pile->next;
  if ((cmd = init_list_cmd()) == NULL)
    return (NULL);
  if ((tmp = malloc(sizeof(t_cmd) * (malloc_size_count(pile) + 2))) == NULL)
    return (NULL);
  if ((tmp[j].cmd = malloc(sizeof(char *) * malloc_size_count(pile) + 2)) == NULL)
    return (NULL);
  while (pile != NULL)
    {
      tmp[j].token = 0;
      if (pile->token == SEP || (my_strcmp(pile->content, "|") == 1))
	{
	  tmp[j].token = get_sep(parser, pile->content);
	  tmp[j].cmd[i] = NULL;
	  if (add_node_cmd(cmd, tmp[j].cmd, tmp[j].token) == -1)
	    return (NULL);
	  j++;
	  i = 0;
	  if ((tmp[j].cmd = malloc(sizeof(char *) * (malloc_size_count(pile) + 1))) == NULL)
	    return (NULL);
	  flag = 1;
	}
      else
	{
	  if ((tmp[j].cmd[i] = my_strdup(pile->content)) == NULL)
	    return (NULL);
	  flag = 0;
	  i++;
	}
      pile = pile->next;
    }
  tmp[j].cmd[i] = NULL;
  if (flag == 0)
    {
      if (add_node_cmd(cmd, tmp[j].cmd, tmp[j].token) == -1)
	return (NULL);
    }
  return (cmd);
}

int			tabr(char **ta)
{
  int			i;

  i = -1;
  while (ta[++i])
    puts(ta[i]);
  return (0);
}

int			get_parse(char *str, t_parser *parser)
{
  char			*tmp;
  char			**table;
  int			i;
  int			j;

  if ((tmp = pre_parse(str, parser)) == NULL)
    return (-1);
  if ((table = str_to_wordtable(tmp, " \t\n")) == NULL)
    return (-1);
  i = 0;
  while (table[i])
    {
      j = 0;
      while (table[i][j])
	{
	  if (table[i][j] < 0)
	    table[i][j] = - table[i][j];
	  j++;
	}
      i++;
    }
  if ((start_parsing(table, parser)) == -1)
    return (-1);
  if ((parser->cmd = end_parsing(parser, 0, 0, 0)) == NULL)
    return (-1);
  return (0);
}

void			print_list(t_cmd *cmd)
{
  t_cmd *tmp;

  tmp = cmd->next;
  while (tmp)
    {
      puts(".: TAB CMD :.");
      tabr(tmp->cmd);
      puts(".: END :.\n");
      tmp = tmp->next;
    }
}

t_cmd			*parsing(char *str, char **path)
{
  t_parser		parser;

  (void) path;
  if ((parser.pile = init_list()) == NULL)
    return (NULL);
  if ((parser.opt = load_opt()) == NULL)
    return (NULL);
  if ((parser.sep = load_sep()) == NULL)
    return (NULL);
  if (get_parse(str, &parser) == -1)
    return (NULL);
  if (error_case(parser.cmd) == -1)
    return (NULL);
  return (parser.cmd);
}
