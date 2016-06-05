/*
** redirect.c for redirect.c in /Users/leandr_g/Documents/Shared folder/42SH/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Sun Jun  5 02:18:19 2016 Gaëtan Léandre
** Last update Sun Jun  5 03:56:54 2016 Gaëtan Léandre
*/

#include	"main.h"

int		right_redir(char **start, char *end, t_dlist *dlist)
{
  (void)start;
  (void)end;
  (void)dlist;
  puts("right");
  return (1);
}

int		dright_redir(char **start, char *end, t_dlist *dlist)
{
  (void)start;
  (void)end;
  (void)dlist;
  puts("dright");
  return (1);
}

int		left_redir(char **start, char *end, t_dlist *dlist)
{
  (void)start;
  (void)end;
  (void)dlist;
  puts("left");
  return (1);
}

int		dleft_redir(char **start, char *end, t_dlist *dlist)
{
  (void)start;
  (void)end;
  (void)dlist;
  puts("dlef");
  return (1);
}
