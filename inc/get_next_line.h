/*
** get_next_line.h for get_next_line in /home/leandr_g/rendu/Janvier_2016/CPE_2015_getnextline
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Mon Jan  4 15:51:07 2016 Gaëtan Léandre
** Last update Mon Jun  6 18:53:39 2016 victor sousa
*/

#ifndef 		READ_SIZE
# define 		READ_SIZE	(14)
#endif /* !READ_SIZE */

#ifndef 		GET_NEXT_LINE_H_
# define 		GET_NEXT_LINE_H_

#include 		<stdlib.h>
#include 		<unistd.h>

typedef struct		s_text
{
  int			i;
  char			*result;
  char			*stock;
}			t_text;

char			*get_next_line(const int fd);

#endif			/*!GET_NEXT_LINE_H_*/
