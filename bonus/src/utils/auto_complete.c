/*
** auto_complete.c for 42sh in /home/leliev_t/rendu/42sh
** 
** Made by tanguy lelievre
** Login   <leliev_t@epitech.net>
** 
** Started on  Mon Jun  6 17:26:53 2016 tanguy lelievre
** Last update Mon Jun  6 19:29:32 2016 tanguy lelievre
*/

# include "main.h"
# include "my_string.h"

int	auto_complete(String string, int *pos_curs)
{
  char	*to_comp;
  char	*name;
  int	i;
  int	j;

  i = -1;
  j = 0;
  if ((to_comp = StringToArray(string, STRING_NO_FREE)) == NULL)
    return (0);
  while (to_comp[++i]);
  while (to_comp[--i] && to_comp[i] != ' ')
    j++;
  name = auto_compleat(&to_comp[++i]);
  if (my_strlen(name) == j)
    return (0);
  while (name[j])
    {
      (*pos_curs)++;
      pushChar(string->data, name[j++]);
    }
  return (1);
}
