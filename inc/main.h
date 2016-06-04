/*
** minishell.h for minishell in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Sun Jan 24 16:52:29 2016 Gaëtan Léandre
** Last update Tue May 31 16:42:38 2016 Ethan Kerdelhue
*/

#ifndef 		_MINISHELL_
# define 		_MINISHELL_

# include		<string.h>
# include 		<sys/types.h>
# include 		<stdio.h>
# include 		<sys/wait.h>
# include		<signal.h>
# include 		<dirent.h>
# include 		<unistd.h>
# include		"my_printf.h"
# include		"my_sprintf.h"
# include 		"list.h"
# include 		"get_next_line.h"

void			disp_pwd(char *pwd);
void			find_name(t_dlist *dlist, char **cmd);
void			launch(t_dlist *dlist, char **cmd);
void			free_tabs(char **str);
void			free_env(t_dlist *dlist);
int			count_words(char *str, char c);
int			get_size_word(char *str, char c);
char			**str_to_wordtab(char *str, char *separate);
int			my_strlen(char *str);
void			my_putchar(char c);
void			my_putstr(char *str);
int			my_strcmp(char *a, char *b);
char			*my_strcat(char *a, char *b);
/*char			*strdup(char *str);*/
char			*my_strcat_no_free(char *a, char *b);
void			my_env(t_dlist *dlist);
void			my_setenv(t_dlist *dlist, char *name, char *params);
void			my_unsetenv(t_dlist *dlist, char *name);
char			*get_name(char *str);
char			*get_params(char *str);
char			*compil_env(t_list *list, t_dlist *dlist, int i);
void			dlist_to_char(t_dlist *dlist);
int			get_env(char **env, t_dlist *dlist);
char			*my_strcpy(char *str);
int			my_getnbr(const char *str);
int			my_exit(t_dlist *dlist, char **cmd);
void			exec_pipe(t_dlist *dlist, char **pipe, int size);
void			make_command(char *cmd, t_dlist *dlist);
void			make_pipe(char *cmd, t_dlist *dlist);
void			sighandler(int sig);
int		        modular_prog_status(char boolean, int value);
char		        *modular_pwd(char boolean, char *new_pwd);
char			*find_with_name(t_dlist *dlist, char *name);
char			*my_strcat_first(char *a, char *b);
int			my_cd(t_dlist *dlist, char *command);
char			*my_strcat_no_free_b(char *a, char *b);

#endif			/*_MINISHELL_*/
