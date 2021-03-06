/*
** get_next_line.c for get_next_line in /home/leandr_g/rendu/Janvier_2016/CPE_2015_getnextline
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Mon Jan  4 15:56:23 2016 Gaëtan Léandre
** Last update Mon Jun  6 19:08:54 2016 victor sousa
*/

#include 		"get_next_line.h"

int			my_strlen_back(char *str)
{
  int			i;

  i = 0;
  while (str[i] != '\0' && str[i] != '\n')
    i++;
  return (i);
}

char			*withnt_back(char *stock)
{
  int			i;
  int			j;
  int			size;
  char			*new;

  size = 0;
  while (stock[size])
    size++;
  i = 0;
  while (stock[i] != '\0' && stock[i] != '\n')
    i++;
  i = (stock[i] == '\0') ? (i) : (i + 1);
  size = size - i;
  if (size == 0)
    return (NULL);
  if ((new = malloc(size + 1)) == NULL)
    return (NULL);
  j = 0;
  while (stock[i])
    new[j++] = stock[i++];
  new[j] = stock[i];
  return (new);
}

int			add_end(t_text *text, char *stock)
{
  int			i;
  int			j;
  int			size;
  char			*new;

  size = my_strlen_back(text->result) + my_strlen_back(stock);
  i = -1;
  j = 0;
  if (size == 0)
    new = text->result;
  else
    {
      if ((new = malloc(size + 1)) == NULL)
	return (-1);
      while (text->result[++i])
	new[i] = text->result[i];
      while (stock[j] != '\0' && stock[j] != '\n')
	new[i++] = stock[j++];
      new[i] = '\0';
      free(text->result);
    }
  text->i = stock[j] == '\n' ? 1 : 0;
  text->result = new;
  text->stock = withnt_back(stock);
  return (0);
}

char			*get_next_line(const int fd)
{
  char			iread[READ_SIZE + 1];
  static char		*stock = NULL;
  t_text		text;
  int			beread;

  text.i = 0;
  beread = 1;
  if (fd < 0 || (text.result = malloc(sizeof(char))) == NULL)
    return (NULL);
  text.result[0] = '\0';
  if (stock != NULL)
    {
      add_end(&text, stock);
      stock = text.stock;
    }
  while (text.i == 0 && (beread = read(fd, iread, READ_SIZE)) != 0)
    {
      iread[beread] = '\0';
      add_end(&text, iread);
      stock = text.stock;
    }
  if (text.result[0] == '\0' && beread == 0)
    return (NULL);
  return (text.result);
}
