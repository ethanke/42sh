/*
** my_string.h for  in /home/sousa_v/perso/prompt_input/inc/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Jun  4 04:41:29 2016 Victor Sousa
** Last update Mon Jun  6 18:52:30 2016 victor sousa
*/

#ifndef			MY_STRING_H_
# define		MY_STRING_H_

# include		<unistd.h>
# include		<stdlib.h>

# define		STRING_NO_FREE	1
# define		STRING_FREE	2

typedef struct		s_char
{
  char			c;
  struct s_char		*next;
}			t_char;

typedef struct		s_string
{
  t_char		*data;
}			t_string;
typedef t_string *	String;

t_char			*pushChar(t_char *string, char c);
t_char			*pushCharAt(t_char *string, char c, int place);
void			deleteCharAt(String string, int pos);
String			formString(const char *str_raw);
void			printString(String string);
String			concatString(String string1, String string2);
String			concatStringAt(String string1, String string2, int pos);
void			freeString(String string);
int			StringLenght(String string);
char			*StringToArray(String string, char needFree);
String			copyStringFrom(String string, int pos);
void			deleteAfterI(String string, int pos);

#endif			/*MY_STRING_H_*/
