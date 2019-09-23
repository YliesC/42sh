/*
** my_readline.h for 42sh in /home/garcin_s/rendu/PSU_2013_42sh
**
** Made by garcin_s
** Login   <garcin_s@epitech.net>
**
** Started on  Tue Apr 22 12:53:58 2014 garcin_s
** Last update Sun May 25 18:06:50 2014 chahi
*/

#ifndef _MY_H_
# define _MY_H_

/*
** INCLUDES
*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <termios.h>
# include <sys/ioctl.h>
# include <ncurses/curses.h>
# include <term.h>
# include <my.h>

/*
** Extern 42sh.h
*/
typedef struct s_history t_history;
struct s_history
{
  int			token;
  struct s_history	*next;
  struct s_history	*prev;
  char			*str;
  int			nb;
};

typedef struct s_env t_env;
struct s_env
{
  int		token;
  struct s_env	*next;
  struct s_env	*prev;
  char		*key;
  char		*value;
};

typedef struct s_alias t_alias;
struct s_alias
{
  int			token;
  struct s_alias	*next;
  struct s_alias	*prev;
  char			*shortkey;
  char			*command;
};

typedef struct	s_utils t_utils;
struct s_utils
{
  t_env		*env;
  t_history	*history;
  t_alias	*alias;
  char		**path;
  int		my_exit;
};

int	add_elem_env(t_env **, char *, char *);
char	*get_env_var(t_utils *, char *);
/*
** MACROS
*/

# define E_TERM	"\033[01;31mERROR:\033[00mTerminal type not found.\n\
For more information, type --help_term\n"
# define E_ENTA	"\033[01;31mERROR:\033[00m Could no access the termcaps\
data.\nFor more information, type --help_term\n"
# define E_ENTB	"\033[01;31mERROR:\033[00m Terminal type is not\
correct.\nFor more information, type --help_term\n"

# define MAX_CMD_LENGTH	4048

/*
** colors
*/

# define RED	"\033[01;31m"
# define RES	"\033[00m"

/*
** keys
*/

# define UP	65
# define DOWN	66
# define LEFT	68
# define RIGHT	67
# define ARROWS	27

/*
** STRUCTURES
*/

typedef struct	s_term
{
  int		fo;
  char		*term;
  char		*buff;
}		t_term;

typedef struct	s_data
{
  int		ir;
  char		*str;
  char		*save;
  t_term	*term;
  int		limit[2];
  char		letter[3];
}		t_data;

/*
** PROTOTYPES
*/

/*
** my_readline.c
*/

char	*my_readline(char *prompt, t_utils *);

/*
** termcaps.c
*/

char	*my_getenv(char *term);
void	set_getattr(int fo, struct termios *termios);
int	init_termcaps(struct termios *termios, t_term *term, t_utils *);

/*
** pool_functions.c
*/

int	my_strlen(char *str);
char	*my_strxcpy(char *dest, char *src, char c);
void	my_strcpy_read(int, int, char *, char);

/*
** check_termcaps.c
*/

int	check_term(t_term *);
int	check_tgetent(int x);

/*
** cursor.c
*/

int	move_cursor(int, int, char *);
char	*my_end(int, char *);
void	put_char(int [2], char *, char *, char *);
void	my_erase(char *, int [2], char *);
void	put_back_curs(int, int);

/*
** cursor.c
*/

void	my_begin(int [2]);
void	my_clear(char *, int, char *);
void	my_cut(int [2], char *, char *, char *);
void	my_stringend(int [2]);
void	my_paste(char *, char *, int [2], char *);

/*
** init_data.c
*/

t_data	*init_data(t_data *);

/*
** empty.c
*/

void	empty_all(t_data *, struct termios termios);

/*
** check_two.c
*/

int	check_things(t_data *, struct termios);

/*
** cursor_history.c
*/
void	my_history(t_data *, t_history *, char *, int *);

#endif
