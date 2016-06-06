/*
** my_printf.c for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Thu Nov 12 12:27:44 2015 Gaëtan Léandre
** Last update Sat Jun  4 07:58:35 2016 Victor Sousa
*/

#include 		"main.h"

void			va_my_putfnbr(int fd, va_list ap)
{
  my_put_fnbr_in(fd, va_arg(ap, double));
}

t_fonct			*init_struct(t_fonct *table)
{
  char			*flag;
  int			i;

  if ((table = malloc(12 * sizeof(t_fonct))) == NULL)
    return (NULL);
  flag = "csiduoxXbSpf";
  i = -1;
  while (++i < 12)
    table[i].flag = flag[i];
  (table[0].f) = va_my_putchar;
  (table[1].f) = va_my_putstr;
  (table[2].f) = va_my_putnbr;
  (table[3].f) = va_my_putnbr;
  (table[4].f) = va_my_putunbr;
  (table[5].f) = va_my_octal;
  (table[6].f) = va_my_examin;
  (table[7].f) = va_my_examaj;
  (table[8].f) = va_my_bin;
  (table[9].f) = va_my_disp_unp;
  (table[10].f) = va_my_adress;
  (table[11].f) = va_my_putfnbr;
  return (table);
}

int			chose_function(char c, t_fonct *table)
{
  int			i;

  i = 0;
  while (i < 12)
    {
      if (c == table[i].flag)
	return (i);
      i++;
    }
  if (c == '\0')
    return (-2);
  return (-1);
}

int			print_fct(va_list ap, t_fonct *table,
				  char *str, t_print pri)
{
  int			fct;
  int			wait;

  pri.i++;
  wait = str[pri.i] == ' ' ? 1 : 0;
  while (str[pri.i] == ' ')
    pri.i++;
  fct = chose_function(str[pri.i], table);
  if (fct == -1)
    {
      my_putchar_in(pri.fd, '%');
      if (str[pri.i] != '%')
	{
	  if (wait == 1)
	    my_putchar_in(pri.fd, ' ');
	  my_putchar_in(pri.fd, str[pri.i]);
	}
    }
  else if (fct > -1)
    {
      if (wait == 1)
	my_putchar_in(pri.fd, ' ');
      table[fct].f(pri.fd, ap);
    }
  return (pri.i);
}

int			my_printf(int fd, char *str, ...)
{
  va_list	ap;
  t_fonct	*table;
  t_print	pri;

  pri.fd = fd;
  table = NULL;
  table = init_struct(table);
  pri.i = 0;
  if (str == NULL || table == NULL)
    return (-1);
  va_start(ap, str);
  while (pri.i < my_strlen(str))
    {
      if (str[pri.i] == '%')
	pri.i = print_fct(ap, table, str, pri);
      else
	my_putchar_in(fd, str[pri.i]);
      pri.i++;
    }
  va_end(ap);
  free(table);
  return (0);
}
