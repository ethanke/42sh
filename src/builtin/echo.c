/*
** echo.c for 42 in /home/leliev_t/rendu/PSU/42sh_temp
** 
** Made by Tanguy LELIEVRE
** Login   <leliev_t@epitech.net>
** 
** Started on  Thu May 26 00:45:12 2016 Tanguy LELIEVRE
** Last update Thu May 26 03:11:24 2016 Tanguy LELIEVRE
*/

# include "main.h"

void	my_echo(char **av)
{
  int	i;
  int	j;

  j = (strcmp(av[0], "-n") != 0) ? 1 : 0;
  i = (j == 1) ? -1 : 0;
  while (av[++i])
    {
      my_putstr(av[i]);
      if (av[i + 1])
	my_putchar(' ');
    }
  if (j == 1)
    my_putchar('\n');
}
