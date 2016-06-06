/*
** history_builtin.c for  in /home/sousa_v/rendu/psu/42_temp/src/builtin/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Mon Jun  6 04:13:17 2016 Victor Sousa
** Last update Mon Jun  6 06:18:29 2016 Victor Sousa
*/

#include	"main.h"
#include	"prompt.h"

int		history_buildin(void)
{
  while (modular_history(0, NULL)->prev != NULL)
    modular_history(1 , modular_history(0, NULL)->prev);
  while (modular_history(0, NULL)->next != NULL)
    {
      printf("%d\t%s\n", modular_history(0, NULL)->id,
	     modular_history(0, NULL)->cmd);
      modular_history(1, modular_history(0, NULL)->next);
    }
  printf("%d\t%s\n", modular_history(0, NULL)->id,
	 modular_history(0, NULL)->cmd);
  return (0);
}
