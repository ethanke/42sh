/*
** disp_msg.c for 42sh in /Users/leandr_g/Documents/Shared folder/42SH/src/utils/
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.eu>
**
** Started on  Mon Jun  6 04:12:11 2016 Gaëtan Léandre
** Last update Mon Jun  6 04:24:00 2016 Gaëtan Léandre
*/

#include		"main.h"

void			disp_msg(int err)
{
  int			i;
  t_error   		error[11] =
    {
    	{SIGHUP, "Hangup"},
    	{SIGQUIT, "Quit (core dumped)"},
    	{SIGABRT, "Abort (core dumped)"},
    	{SIGBUS, "Bus error (core dumped)"},
    	{SIGFPE, "Floating exception (core dumped)"},
    	{SIGKILL, "Killed"},
    	{SIGUSR1, "User signal 1"},
    	{SIGSEGV, "Segmentation fault (core dumped)"},
    	{SIGUSR2, "User signal 2"},
    	{SIGPIPE, "Broken pipe"},
    	{SIGTERM, "Terminated"},
    };

  i = 0;
  while (i < 11)
    {
      if (err == error[i].sign)
	my_printf(2, "%s\n", error[i].msg);
      i++;
    }
  }
