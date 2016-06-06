/*
** xfree.c for  in /home/sousa_v/perso/prompt_input/src/misc/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Fri Jun  3 15:07:51 2016 Victor Sousa
** Last update Fri Jun  3 15:08:21 2016 Victor Sousa
*/

#include	"prompt.h"

void		xfree(void *ptr)
{
  if (ptr != NULL)
    free(ptr);
}
