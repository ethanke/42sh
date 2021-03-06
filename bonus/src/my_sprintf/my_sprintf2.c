/*
** my_printf2.c for my_printf in /home/leandr_g/rendu/Novembre_2015/PSU_2015_my_printf
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Fri Nov 13 10:51:48 2015 Gaëtan Léandre
** Last update Sat May 14 00:59:07 2016 Philippe Lefevre
*/

#include 		"main.h"

char			*va_my_putchar_s(va_list ap)
{
  char			*str;

  if ((str = malloc_and_init()) == NULL)
    return (NULL);
  str = my_strcatchar(str, va_arg(ap, int));
  return (str);
}

char			*va_my_putstr_s(va_list ap)
{
  char			*str;

  if ((str = malloc_and_init()) == NULL)
    return (NULL);
  str = my_strcatnofree(str, va_arg(ap, char*));
  return (str);
}

char			*va_my_putnbr_s(va_list ap)
{
  return (my_put_nbr_s(va_arg(ap, int)));
}

char			*va_my_putunbr_s(va_list ap)
{
  return (my_put_unbr_s(va_arg(ap, unsigned int)));
}

char			*va_my_disp_unp_s(va_list ap)
{
  return (disp_unprintablele_s(va_arg(ap, char*)));
}
