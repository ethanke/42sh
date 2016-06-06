/*
** glob.c for 42 in /Users/leandr_g/Documents/Shared folder/42SH/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Jun  6 17:40:20 2016 Gaëtan Léandre
** Last update Mon Jun  6 19:09:43 2016 Gaëtan Léandre
*/

#include	"main.h"

static int	globerr(const char *path, int eerrno)
{
  my_printf(2, "%s: %s\n", path, strerror(eerrno));
  return 0;
}



char		**my_tabcat(char **a, char **b)
{
  char		**table;
  int		size;
  int		i;

  size = my_tablestrlen(a) + my_tablestrlen(b);
  if ((table = malloc(sizeof(char *) * (size + 1))) == NULL)
    return (NULL);
  i = 0;
  size = -1;
  while (a && a[i])
    {
      table[i] = my_strdup(a[i]);
      i++;
    }
  while (b && b[++size])
    table[i++] = my_strdup(b[size]);
  table[i] = '\0';
  if (a != NULL)
    free_tables(a);
  i = 0;
  return (table);
}

char		**make_glob(char **cmd)
{
  glob_t	results;
  int		i;
  int		ret;
  int		flags;
  char		**table;

  i = 0;
  flags = 0;
  table = NULL;
  flags |= GLOB_NOCHECK;
  while (cmd[i])
    {
      ret = glob(cmd[i], flags, globerr, &results);
      if (ret == GLOB_NOMATCH || ret == 0)
	table = my_tabcat(table, results.gl_pathv);
      i++;
    }
  i = 0;
  if (table != NULL)
    return (table);
  return (cmd);
}

char		*auto_compleat(char *cmd)
{
  glob_t	results;
  int		ret;
  int		flags;
  char		*dup;

  dup = my_strcat_no_free_b(cmd, "*");
  flags = 0;
  ret = glob(dup, flags, globerr, &results);
  free(dup);
  if (ret == 0 && results.gl_pathc == 1)
    return (results.gl_pathv[0]);
  return (cmd);
}
