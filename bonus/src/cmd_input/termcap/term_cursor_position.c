/*
** term_cursor_position.c for  in /home/sousa_v/perso/prompt_input/src/termcap/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Jun  4 04:59:54 2016 Victor Sousa
** Last update Sat Jun  4 05:00:25 2016 Victor Sousa
*/

#include	"prompt.h"

void		assign_value_pos(int *x, int *y, char *buff)
{
  char		num[10];
  int		indice;
  int		indice2;

  indice = 2;
  while (buff[indice] != '\0' && buff[indice] != ';')
    {
      num[indice - 2] = buff[indice];
      indice = indice + 1;
    }
  num[indice - 2] = '\0';
  *y = atoi(num) - 1;
  indice2 = 0;
  indice = indice + 1;
  while (buff[indice] != '\0' &&
	 buff[indice] != '\0' && buff[indice] != ';')
    {
      num[indice2] = buff[indice];
      indice = indice + 1;
      indice2 = indice2 + 1;
    }
  num[indice - 2] = '\0';
  *x = atoi(num) - 1;
}

void		get_pos_curser(int *x, int *y, int fd)
{
  char		buff[30];
  int		indice;
  int		i;

  *x = 0;
  *y = 0;
  i = 0;
  memset(buff, 0, 30);
  if (write(fd, POSCURSEUR, strlen(POSCURSEUR)) == -1 ||
      (indice = read(fd, buff, 19)) == -1)
    return ;
  buff[indice] = '\0';
  while (buff[0] != 27 && i < 100)
    {
      memset(buff, 0, 30);
      if (write(fd, POSCURSEUR, strlen(POSCURSEUR)) == -1)
	return ;
      if ((indice = read(fd, buff, 19)) == -1)
	return ;
      buff[indice] = '\0';
      i++;
    }
  if (i == 100)
    return ;
  assign_value_pos(x, y, buff);
}
