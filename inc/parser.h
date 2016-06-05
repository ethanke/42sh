/*
** parser.h for  in /Users/ethankerdelhue/Documents/Shared/42sh/include/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed May 25 07:15:37 2016 Ethan Kerdelhue
** Last update Sun Jun  5 03:20:04 2016 Ethan Kerdelhue
*/

#ifndef 		_PARSER_
# define 		_PARSER_

#define			CMD		0
#define			OPT		1
#define			SEP		2
#define			OPE		3
#define			FIL		4
#define			SKI		-1
#define			PV		0
#define			OU		1
#define			ET		2
#define			PI		3

#include		<stdlib.h>
#include		<unistd.h>
#include		<stdio.h>
#include		<string.h>

typedef struct		s_pile
{
  char			token;
  char			*content;
  struct s_pile		*next;
  struct s_pile		*prev;
}			t_pile;

typedef struct		s_cmd
{
  char			**cmd;
  char			token;
  struct s_cmd		*next;
  struct s_cmd		*prev;
}			t_cmd;

typedef struct		s_parser
{
  char			**opt;
  char			**sep;
  char			**path;
  t_pile		*pile;
  t_cmd			**cmd;
}			t_parser;

int		print_tab(char **table);
int		free_for_all(char **table);
int		check_last(t_pile *pile);
char	        *my_strcat_wm(char *s, char *s2);
int		add_node(t_pile *pile, char token, char *content);
int		my_strlen(char *str);
char		**str_to_wordtable(char *s, char *delim);
int		my_strncmp(char *s1, char *s2, int n);
int		my_strcmp(char *s1, char *s2);
char		*my_strcat(char *s1, char *s2);
char		*get_next_line(int fd);
int		free_for_all(char **table);
int		get_sep(t_parser *parser, char *str);
char		*pre_parse(char *str, t_parser *parser);
int		start_parsing(char **table, t_parser *parser);
t_cmd		*parsing(char *str, char **path);

		/* OPT */
int		isopt(char *str, t_parser *parser);
int		opt_parsing(char **table, t_parser *parser, int i, char *flag);
char		**load_opt();

		/* SEP */
int		issep(char *str, t_parser *parser);
int		sep_parsing(char **table, t_parser *parser, int i, char *flag);
char		**load_sep();

		/* EPUR OPT */
char		*epur_opt(char *str, char **delim, int i, int k);
char		*epur_sep(char *str, char **delim, int i, int k);
char		*epur_string(char *str);

		/* LINK LIST */
int		add_node(t_pile *pile, char token, char *content);
t_pile		*init_list();
int		add_node_cmd(t_cmd *cmd, char **table, char token);
t_cmd		*init_list_cmd();

		/* CMD */
int		iscmd(char *str, t_parser *parser);
int		cmd_parsing(char **table, t_parser *parser, int i, char *flag);
int		special_case(char **table, t_parser *parser, int i, char *flag);

t_cmd		*get_parse(char *str, t_parser *parser);

#endif			/*_PARSER_*/
