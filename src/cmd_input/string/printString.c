/*
** printString.c for  in /home/sousa_v/perso/my_string/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Thu Jun  2 18:34:04 2016 Victor Sousa
** Last update Thu Jun  2 19:06:32 2016 Victor Sousa
*/

#include	"my_string.h"

static void	my_putchar(char c)
{
  write(1, &c, 1);
}

void		printString(String string)
{
  t_char	*c;

  c = string->data;
  while (c != NULL)
    {
      my_putchar(c->c);
      c = c->next;
    }
}
