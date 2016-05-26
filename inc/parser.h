/*
** parser.h for  in /Users/ethankerdelhue/Documents/Shared/42sh/include/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Wed May 25 07:15:37 2016 Ethan Kerdelhue
** Last update Wed May 25 16:54:05 2016 Ethan Kerdelhue
*/

#ifndef 		_PARSER_
# define 		_PARSER_

#define			CMD		0
#define			OPT		1
#define			INS		2
#define			SKI		3

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
  char			**path;
  t_pile		*pile;
}			t_parser;

char		**my_str_to_wordtab(char *s, char *delim);
char		*my_strcat(char *s1, char *s2);
char		*get_next_line(int fd);

#endif			/*_PARSER_*/
