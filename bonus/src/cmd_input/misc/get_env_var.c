/*
** get_env_var.c for  in /home/sousa_v/perso/prompt_input/src/misc/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Jun  4 03:20:26 2016 Victor Sousa
** Last update Sat Jun  4 03:21:51 2016 Victor Sousa
*/

#include	"prompt.h"

char		*get_env_var(char *var, char **env)
{
  int		varlen;
  char		*varegal;

  varlen = strlen(var);
  if ((varegal = malloc((varlen + 2) * sizeof(char))) == NULL)
    return (NULL);
  my_strncpy(varegal, var, -1);
  varegal[varlen] = '=';
  varegal[varlen + 1] = '\0';
  while ((env != NULL) && (env[0] != NULL))
    {
      if (my_strncmp(varegal, env[0], varlen + 1) == 0)
        {
          free(varegal);
          return (&(env[0][varlen + 1]));
        }
      env = &env[1];
    }
  free(varegal);
  return (NULL);
}
