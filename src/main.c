/*
** main.c for minishell1 in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Sat Jan 23 02:27:31 2016 Gaëtan Léandre
** Last update Mon Jun  6 21:38:45 2016 Gaëtan Léandre
*/

#include 		"main.h"

char			*reverse_inib(char *str)
{
  int			i;
  int			j;
  char			flag;
  char			*new;

  if ((new = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (str);
  j = ((i = -1) + (flag = 0)) * 0;
  while (str[++i])
    {
      if (str[i] == '\"')
	{
	  if (flag == 0)
	    flag = 1;
	  else
	    flag = 0;
	}
      else if (flag)
	new[j++] = - str[i];
      else
	new[j++] = str[i];
    }
  new[j] = '\0';
  free(str);
  return (new);
}

int			init_line(t_edit_line *line)
{
  if ((line->fd_tty = open("/dev/tty", O_RDWR)) == -1)
    return (-1);
  my_put_termcap(line->fd_tty, NULL);
  if (reset_save_mode(0, line->fd_tty) == EXIT_FAILURE)
    {
      dprintf(2, "Error SAVE termcap\n");
      return (-1);
    }
  if (mode_raw(line->fd_tty) == EXIT_FAILURE)
    {
      dprintf(2, "Error mod_raw termcap\n");
      return (-1);
    }
  return (0);
}

int			main(int ac, char **av, char **env)
{
  t_dlist		*dlist;
  char			*cmd;
  t_edit_line		line;
  int			result;

  (void)ac;
  (void)av;
  modular_history(1, NULL);
  result = 0;
  if (init_line(&line) == -1 || (dlist = create_dlist()) == NULL)
    return (-1);
  get_env(env, dlist);
  modular_pwd(1, dlist->pwd);
  disp_pwd(modular_pwd(0, NULL));
  signal(SIGINT, sighandler);
  modular_line(1, &line);
  while ((cmd = get_prompt_input(&line, dlist->env)) != NULL)
    {
      cmd = reverse_inib(cmd);
      result = send_cmd(parsing(cmd, dlist->path), dlist);
      disp_pwd(modular_pwd(0, NULL));
      free(cmd);
    }
  my_putchar('\n');
  return ((isatty(0) != 1) ? result : 0);
}
