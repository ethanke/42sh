/*
** parser.h for  in /Users/ethankerdelhue/Documents/Shared/42sh/include/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed May 25 07:15:37 2016 Ethan Kerdelhue
** Last update Mon Jun  6 22:20:36 2016 Ethan Kerdelhue
*/

#ifndef 		PARSER_H_
# define 		PARSER_H_

#include		<stdlib.h>
#include		<unistd.h>
#include		<stdio.h>
#include		<string.h>

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
  t_cmd			*cmd;
}			t_parser;

int			malloc_size_count(t_pile *pile);
int			list_len(t_cmd *cmd);
void			list_print(t_pile *pile);
char			*my_cat(char *a, char *b);
int			count_size_sep(char *str, char **sep);
int                     is_a_to_delete(char c, char *to_delete);
char			*my_my_strcat(char *a, char *b);
void			list_print(t_pile *pile);
int			free_for_all(char **table);
int			check_last(t_pile *pile);
char			*my_strcat_wm(char *s, char *s2);
int			my_strlen(char *str);
char			**str_to_wordtable(char *s, char *delim);
int			my_strncmp(char *s1, char *s2, int n);
int			my_strcmp(char *s1, char *s2);
char			*my_strcat(char *s1, char *s2);
char			*get_next_line(int fd);
int			free_for_all(char **table);
int			get_sep(t_parser *parser, char *str);
char			*pre_parse(char *str, t_parser *parser);
int			start_parsing(char **table, t_parser *parser);
t_cmd			*parsing(char *str, char **path);

			/* OPT */
int			isopt(char *str, t_parser *parser);
int			opt_parsing(char **table, t_parser *parser, int i, char *flag);
char			**load_opt();

			/* SEP */
int			issep(char *str, t_parser *parser);
int			sep_parsing(char **table, t_parser *parser, int i, char *flag);
char			**load_sep();

			/* EPUR OPT */
char			*epur_opt(char *str, char **delim, int i, int k);
char			*epur_sep(char *str, char **delim, int i, int k);
char			*epur_string(char *str);

			/* LINK LIST */
t_pile			*add_node(t_pile *pile, char token, char *content);
t_pile			*init_list();
int			add_node_cmd(t_cmd *cmd, char **table, char token);
t_cmd			*init_list_cmd();

			/* CMD */
int			iscmd(char *str, t_parser *parser);
int			cmd_parsing(char **table, t_parser *parser, int i, char *flag);
int			get_parse(char *str, t_parser *parser, int i, int j);
int			error_case(t_cmd *cmd);
int			tablen(char **table);

#endif			/*PARSER_H_*/
