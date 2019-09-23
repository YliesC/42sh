/*
** 42sh.h for 42sh in /home/chahi_y/rendu/PSU_2013_42sh
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Wed Apr 16 14:02:18 2014 chahi
** Last update Wed Aug 13 16:57:01 2014 chahi
*/

#ifndef MYSH_H_
# define MYSH_H_

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <dirent.h>
# include <fcntl.h>
# include <string.h>
# include <strings.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <my.h>

# define ENV_SEPARATOR	"="
# define HISTORY_FILE	".history"
# define PATH_FILE	".path"
# define BUILTIN	10
# define DEFAULT	"\033[0m"
# define HIGHLIGHT	"\033[1m"
# define BLINK		"\033[5m"
# define BLACK		"\033[30m"
# define WHITE		"\033[37m"
# define RED		"\033[31m"
# define BLUE		"\033[34m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define PURPLE		"\033[35m"
# define CYAN		"\033[36m"
# define UNDERLINE	""
# define BOLD		""

typedef struct s_base t_base;
struct s_base
{
  int		token;
  struct s_base *next;
  struct s_base *prev;
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

typedef struct s_history t_history;
struct s_history
{
  int			token;
  struct s_history	*next;
  struct s_history	*prev;
  char			*str;
  int			nb;
};

typedef struct		s_token
{
  int			id;
  char			*str;
  struct s_token	*next;
}			t_token;

typedef struct		s_redi
{
  int			id;
  int			type;
  char			*file;
  char			*argv;
  struct s_redi		*next;
}			t_redi;

typedef struct	s_utils t_utils;
struct s_utils
{
  t_env		*env;
  t_history	*history;
  t_alias	*alias;
  char		**path;
  int		my_exit;
  int		last_ret;
};

typedef struct s_echo t_echo;
struct s_echo
{
  int	e_flag;
  int	E_flag;
  int	n_flag;
  int	output;
  char	slash[9];
  char	letter[9];
};

typedef struct s_builtin t_builtin;
struct s_builtin
{
  char	str[25];
  int	(*func)(char **, t_utils *);
};

/*
** main.c
*/
int	main(int, char **, char **);
int	my_read(t_utils *);
char	*my_readline(char *, t_utils *);
void	my_handler(int);
void	my_free(t_utils *);

/*
** main_loop.c
*/
int	main_loop(char *, t_utils *);

/*
** init_struct.c
*/
void	init_struct(t_utils *);

/* ----- */
/* ALIAS */
/* ----- */
/*
** gest_alias.c
*/
int	add_elem_alias(t_alias **, char *, char *);
int	remove_elem_alias(t_alias **, t_alias **);

/* ------- */
/* BUILTIN */
/* ------- */
/*
** Builtin functions
*/
int	__cd(char **, t_utils *);
int	__env(char **, t_utils *);
int	__setenv(char **, t_utils *);
int	__unsetenv(char **, t_utils *);
int	__alias(char **, t_utils *);
int	__unalias(char **, t_utils *);
int	__history(char **, t_utils *);
int	__echo(char **, t_utils *);
int	__exit(char **, t_utils *);
int	__clear_screen(char **, t_utils *);

int	init_builtin(t_builtin *);
int	builtin(char *, char **, t_utils *);
/*
** echo.c
*/
int	is_in_str(char, char *);
int	get_option(char *, t_echo *);
int	get_output(char **, t_echo *);
void	init_echo(t_echo *);

/*
**echo_options.c
*/
int	option_e(char **, t_echo *);
int	option_upper_e(char **, t_echo *);
int	option_n(char **, t_echo *);
int	no_option(char **, t_echo *);

/* ----------- */
/* ENVIRONMENT */
/* ----------- */
/*
** check_env.c
*/
int	check_env(t_utils *, char **);

/*
** fill_env.c
*/
int	fill_env(t_utils *, char **);

/*
** gest_env.c
*/
int	add_elem_env(t_env **, char *, char *);
int	remove_elem_env(t_env **, t_env **);

/* ------- */
/* HISTORY */
/* ------- */
/*
** history.c
*/
int	add_history_to_file(char *, t_history *);
int	add_history_to_list(t_history **);
int	remove_history(t_history **);
char	*create_path_history();

/*
** gest_history.c
*/
int	add_elem_history(char *, t_utils *);
int	remove_elem_history(t_history **, t_history **);

/* ---------- */
/* LISTE_GEST */
/* ---------- */
/*
** add_to_list.c
*/
void	add_first(t_base **, t_base **);
t_base	*add_to_list(t_base **, int);

/*
** free_struct.c
*/
int	free_env(t_env *);
int	free_history(t_history *);
int	free_struct(t_base *);

/*
** print_liste.c
*/
void	print_elem(t_base *);
void	print_liste(t_base *);

/* ---- */
/* MISC */
/* ---- */
/*
** misc.c
*/
char	*get_env_var(t_utils *, char *);
char	*set_env_var(t_utils *, char *, char *);
char	*fill_env_i();
int	print_error(char *);

/*
** utils.c
*/
int	get_path(t_utils *);

/* ---- */
/* EXEC */
/* ---- */
/*
** func.c
*/
char	*my_exec_create(char *, char **);

/*
** and_or.c
*/
double	next_and_or_null(t_token *);
int	and_or(char *, t_utils *);

/*
** make_token.c
*/
void	my_free_2(char **, t_token *);
void	my_refull(t_token **);
int	my_continue(int, double *);
int	my_id_str(char *);

/*
** execute.c
*/
int	my_next(int, double *, t_token **);
int	execute(char *, char **, t_utils *);

/*
** parse.c
*/
int	my_parse(char *, t_token **);

/*
** pipes.c
*/
int	my_pipes(t_token *, char **, t_utils *);
int	my_firstwordget(char **, char **, char *);
t_token	*my_get_token(t_token *, int, int);

/*
** make_redir.c
*/
int	my_redir(t_token *, char **, t_utils *);

/*
** redirs.c
*/
int	my_handle_red(t_redi *, char **, t_utils *);
int	my_right_r(t_redi *, char **, t_utils *);
int    	my_right_rd(t_redi *, char **, t_utils *);
int    	my_left_r(t_redi *, char **, t_utils *);
int	check_prev_sep(t_token *, int);

/*
** dlred.c
*/
int	my_left_rd(t_redi *, char **, t_utils *);
int	replaces_env_var(char **, char **);

/*
** mult_red.c
*/
int	mult_redi(t_redi *, char **, t_utils *);
void	my_free_3(t_redi *);

/*
** my_exit.c
*/
int	my_exit_1(int, t_token *, char **, t_utils *);
int	my_exit_2(int, t_redi *, char **, t_utils *);
int	my_execute2(char **, t_utils *, char **);
int	replaces_dol_inte(char **, int);

/*
** signals.c
*/
int	my_signals(int);
int	my_check_token(t_token *);

/* ---------- */
/* PREPROCESS */
/* ---------- */
/*
** clear_command.c
*/
char	*clear_command(char *, int);

/*
** gest_error_cmd.c
*/
int	check_error_token(char *);
int	check_nb_token(char *);
int	check_first_token(char *);
int	check_double_token(char **);

/*
** misc.c
*/
int	count_sep(char *, char);
int	contain_sep(char *);

#endif
