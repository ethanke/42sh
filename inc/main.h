/*
** minishell.h for minishell in /home/leandr_g/rendu/Janvier_2016/PSU_2015_minishell1
**
** Made by Gaëtan Léandre
** Login   <leandr_g@epitech.net>
**
** Started on  Sun Jan 24 16:52:29 2016 Gaëtan Léandre
** Last update Sun Jun  5 21:00:56 2016 Victor Sousa
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
# include		"prompt.h"
# include		"parser.h"

char			*my_strdup(char *str);
void			disp_pwd(char *pwd);
void			find_name(t_dlist *dlist, char **cmd);
int			launch(t_dlist *dlist, char **cmd);
void			free_tables(char **str);
void			free_env(t_dlist *dlist);
int			count_words(char *str, char c);
int			get_size_word(char *str, char c);
char			**str_to_wordtable(char *str, char *separate);
int			my_strlen(char *str);
void			my_putchar(char c);
void			my_putstr(char *str);
int			my_strcmp(char *a, char *b);
char			*my_strcat(char *a, char *b);
/*char			*strdup(char *str);*/
char			*my_strcat_no_free(char *a, char *b);
int			my_env(t_dlist *dlist);
int			my_setenv(t_dlist *dlist, char *name, char *params);
int			my_unsetenv(t_dlist *dlist, char *name);
char			*get_name(char *str);
char			*get_params(char *str);
char			*compil_env(t_list *list, t_dlist *dlist, int i);
void			dlist_to_char(t_dlist *dlist);
int			get_env(char **env, t_dlist *dlist);
char			*my_strcpy(char *dest, char *str);
int			my_getnbr(const char *str);
int			my_exit(t_dlist *dlist, char **cmd);
int			exec_pipe(t_dlist *dlist, t_cmd *cmd, int size);
int			make_command(char **cmd, t_dlist *dlist);
int			make_pipe(t_cmd *cmd, t_dlist *dlist);
void			sighandler(int sig);
String			modular_clip(char boolean, String new_buff, int pos);
int		        modular_prog_status(char boolean, int value);
char		        *modular_pwd(char boolean, char *new_pwd);
char			*find_with_name(t_dlist *dlist, char *name);
char			*my_strcat_first(char *a, char *b);
int			my_cd(t_dlist *dlist, char *command);
char			*my_strcat_no_free_b(char *a, char *b);
int			exec_redir(char **cmd, t_dlist *dlist);
int			right_redir(char **start, char *end, t_dlist *dlist);
int			dright_redir(char **start, char *end, t_dlist *dlist);
int			left_redir(char **start, char *end, t_dlist *dlist);
int			dleft_redir(char **start, char *end, t_dlist *dlist);
void			send_cmd(t_cmd *cmd, t_dlist *dlist);

#endif			/*_MINISHELL_*/
