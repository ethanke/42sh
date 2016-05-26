/*
** sighandler.c for  in /home/sousa_v/rendu/psu/42_temp/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed May 25 23:43:24 2016 Victor Sousa
** Last update Wed May 25 23:43:26 2016 Victor Sousa
*/

#include		"minishell.h"

void            sighandler(int sig)
{
  if (sig == 2)
    {
      my_putstr("\b\b  \n");
      disp_pwd(modular_pwd(0, NULL));
    }
  signal(SIGINT, sighandler);
}

