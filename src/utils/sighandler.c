/*
** sighandler.c for  in /home/sousa_v/rendu/psu/42_temp/src/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Wed May 25 23:43:24 2016 Victor Sousa
** Last update Mon Jun  6 23:33:43 2016 victor sousa
*/

#include		"main.h"

void            sighandler(int sig)
{
  if (sig == 2)
    {
      modular_prog_status(1, 2);
      printf("\b\b  \n");
      disp_pwd(modular_pwd(0, NULL));
    }
  signal(SIGINT, sighandler);
}
