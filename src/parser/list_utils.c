/*
** list_utils.c for  in /Users/ethankerdelhue/Documents/Shared/42sh/src/parser/
**
** Made by Ethan Kerdelhue
** Login   <kerdel_e@epitech.eu>
**
** Started on  Mon Jun  6 22:01:18 2016 Ethan Kerdelhue
** Last update Mon Jun  6 22:05:49 2016 Ethan Kerdelhue
*/

#include		"parser.h"

int			malloc_size_count(t_pile *pile)
{
  int			size;
  t_pile		*tmp;

  tmp = pile;
  size = 0;
  while (tmp != NULL)
    {
      size++;
      tmp = tmp->next;
    }
  return (size + 1);
}

int			list_len(t_cmd *cmd)
{
  int			i;
  t_cmd			*tmp;

  tmp = cmd;
  i = 0;
  while (tmp)
    {
      i++;
      tmp = tmp->next;
    }
  printf("LIST LEN : %d", i);
  return (0);
}

void			list_print(t_pile *pile)
{
  t_pile 		*tmp;

  tmp = pile;
  while (tmp)
    {
      printf("C: %s \n", tmp->content);
      tmp = tmp->next;
    }
}

int			tabr(char **ta)
{
  int			i;

  i = -1;
  while (ta[++i])
    puts(ta[i]);
  return (0);
}

void			print_list(t_cmd *cmd)
{
  t_cmd *tmp;

  tmp = cmd->next;
  while (tmp)
    {
      puts(".: TAB CMD :.");
      tabr(tmp->cmd);
      puts(".: END :.\n");
      tmp = tmp->next;
    }
}
