/*
** parser.h for  in /Users/ethankerdelhue/Documents/Shared/42sh/include/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed May 25 07:15:37 2016 Ethan Kerdelhue
** Last update Tue May 31 16:02:20 2016 Ethan Kerdelhue
*/

#ifndef 		_PARSER_
# define 		_PARSER_

#define			CMD		0
#define			OPT		1
#define			SEP		2
#define			SKI		-1

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

typedef struct		s_parser
{
  char			**opt;
  char			**sep;
  char			**path;
  t_pile		*pile;
}			t_parser;

typedef struct		s_cmd
{
  char			**cmd;
  char			token;
}			t_cmd;

char	        *my_strcat_wm(char *s, char *s2);
int		add_node(t_pile *pile, char token, char *content);
int		my_strlen(char *str);
char		**str_to_wordtab(char *s, char *delim);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_strcat(char *s1, char *s2);
char		*get_next_line(int fd);

		/* OPT */
int		isopt(char *str, t_parser *parser);
int		opt_parsing(char **tab, t_parser *parser, int i, char *flag);
char		**load_opt();

		/* SEP */
int		issep(char *str, t_parser *parser);
int		sep_parsing(char **tab, t_parser *parser, int i, char *flag);
char		**load_sep();

		/* EPUR OPT */
char		*epur_opt(char *str, char **delim, int i, int k);
char		*epur_sep(char *str, char **delim, int i, int k);
char		*epur_string(char *str);


#endif			/*_PARSER_*/
