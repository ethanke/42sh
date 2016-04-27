/*
** my_getnbr.c for my_getnbr in /home/leandr_g/rendu/Piscine_C_J04
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Thu Oct  1 21:21:45 2015 Gaëtan Léandre
** Last update Sat Apr  9 04:11:05 2016 Gaëtan Léandre
*/

#include 		"minishell.h"

int			verif(int number, char add, int less)
{
  if (number <= 214748364)
    {
      if (number == 214748364)
	{
	  if ((less < 0 && add <= 56) || (less > 0 && add <= 55))
	    {
	      number = number * 10;
	      number = number + add - 48;
	      return (number);
	    }
	}
      else
	{
	  number = number * 10;
	  number = number + add - 48;
	  return (number);
	}
    }
  return (-1);
}

int			my_getnbr(const char *str)
{
  int			number;
  int			less = 1;
  int			i;

  i = 0;
  number = 0;
  while (str[i] == ' ' || str[i] == '\n')
    i++;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i] == '-')
	less = -1 * less;
      i++;
    }
  while (str[i] > 47 && str[i] < 58)
    {
      number = verif(number, str[i], less);
      if (number == -1)
	return (0);
      i++;
    }
  return (number * less);
}
