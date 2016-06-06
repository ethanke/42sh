/*
** glob.c for 42 in /Users/leandr_g/Documents/Shared folder/42SH/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Jun  6 17:40:20 2016 Gaëtan Léandre
** Last update Mon Jun  6 18:01:01 2016 Gaëtan Léandre
*/

#include	"main.h"

int globerr(const char *path, int eerrno)
{
	my_printf(2, "%s: %s\n", path, strerror(eerrno));
	return 0;
}

char		**make_glob(char **cmd)
{
  glob_t	results;
  int		i;
  int		ret;
  int		flags;

  i = 0;
  flags = 0;
  flags |= GLOB_NOCHECK;
  flags = (i > 1 ? GLOB_APPEND : 0);
  while (cmd[i])
    {
      ret = glob(cmd[i], flags, globerr, &results);
      i++;
    }
  if (ret == GLOB_NOMATCH || ret == 0)
    return (results.gl_pathv);
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
