/*
** prompt.h for  in /home/sousa_v/rendu/psu/42_temp/inc/
**
** Made by Victor Sousa
** Login   <sousa_v@epitech.eu>
**
** Started on  Sat Jun  4 08:03:57 2016 Victor Sousa
** Last update Mon Jun  6 22:15:00 2016 victor sousa
*/

#ifndef 		PROMPT_H_
# define 		PROMPT_H_

# include		<stdio.h>
# include		<stdlib.h>
# include		<unistd.h>
# include		<string.h>

# include		<sys/stat.h>
# include		<sys/ioctl.h>
# include		<fcntl.h>
# include 		<term.h>
# include		<poll.h>

# include		"my_string.h"

# define 		RESTORE		1
# define 		SAVE		0
# define 		CLOSE_TTY	-2

# define 		POSCURSEUR	"\033[6n"

# define 		KEY_LEFT      	"\x1B\x5B\x44"
# define 		KEY_RIGHT     	"\x1B\x5B\x43"
# define 		KEY_UP      	"\x1B\x5B\x41"
# define 		KEY_DOWN     	"\x1B\x5B\x42"
# define 		KEY_START    	"\x1B\x4F\x48"
# define 		KEY_END     	"\x1B\x4F\x46"

# define 		ENTER		'\n'
# define		DEL		127
# define		TAB		'\t'
# define 		CTRLK		11
# define 		CTRLY		25
# define 		CTRLU		21
# define 		CTRLL		12
# define 		CTRLD		4
# define 		CTRLA		1
# define 		CTRLE		5

typedef struct		s_termcap
{
  char			*str_cl;
  char			*str_do;
  char			*str_up;
  char			*str_le;
  char			*str_ri;
  char			*str_ce;
  char			*str_cd;
}			t_termcap;

typedef struct		s_edit_line
{
  int			fd_tty;
  t_termcap		termcap;
  String		output_string;
  String		clip_string;
  int			start_pos_x;
  int			start_pos_y;
  int			cur_pos_x;
  int			cur_pos_y;
}			t_edit_line;

typedef struct		s_history
{
  int			id;
  char			*cmd;
  struct s_history	*prev;
  struct s_history	*next;
}			t_history;

char			*get_prompt_input(t_edit_line *line, char **env);

			/*TERMCAP*/
int			my_put_termcap(int flag, char *capacity);
char			*my_tgetstr(char *cap);
int			init_capacity_termcap(t_termcap *termcap);
int			mode_raw(int fd);
int			reset_mode(struct termios t, int fd);
int			reset_save_mode(int type, int fd);
int			curseur(int x, int y);
void			get_pos_curser(int *x, int *y, int fd);
void			term_refresh(t_edit_line *line);
int			get_termsize_x(void);
int			get_termsize_y(void);

			/*MISC*/
void			xfree(void *ptr);
int 			dprintf(int fd, const char *format, ...);
int			my_prompt_strcmp(char *str1, char *str2);
int			my_strncmp(char *s1, char *s2, int n);
void			my_strncpy(char *dest, char *src, int n);
char			*get_env_var(char *var, char **env);
int			my_clear_screen(t_edit_line *line);
int             	modular_prog_status(char boolean, int value);
String			modular_clip(char boolean, String new_buff, int pos);
t_history		*modular_history(char boolean, t_history *new_history);
t_history		*add_to_history(t_history *list, int id, char *cmd);
t_edit_line		*modular_line(char boolean, t_edit_line *new_line);
int			func_key_up(t_edit_line *line);
int			func_key_down(t_edit_line *line);
int			set_value_start(t_edit_line *line,
					struct pollfd *pfd,
					int *pr);
int			get_tty(char **env, t_edit_line *line);
int			init_edition_line(char **env, t_edit_line *line);
int			init_edition_line(char **env, t_edit_line *line);
int			get_last_history_id();
int			get_read_ret(t_edit_line *line, char *buff, char *out, int ret);
int			if_ctrld(char *buff, t_edit_line *line);
int			if_enter(char *buff);
int			if_ctrll(char *buff, t_edit_line *line);
int			if_side(char *buff, t_edit_line *line);
int			if_side2(char *buff, t_edit_line *line);
int			if_delete(char *buff, t_edit_line *line);
int			if_paste(char *buff, t_edit_line *line);

#endif		/*PROMPT_H_*/
