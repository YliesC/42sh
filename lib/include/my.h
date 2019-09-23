/*
** my.h for libmy in /home/chahi_y/lib/libmy
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Wed Mar 19 14:25:40 2014 chahi
** Last update Sun May 25 17:25:40 2014 chahi
*/

#ifndef MY_H_
# define MY_H_

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define CHECK_RETURN(x, y, z) if ((x) == (y)) return (z)
# define READ (1)

/*
** Structures
*/
typedef struct s_get t_get;
struct s_get
{
  int    j;
  int    len;
  char   buff[READ + 1];
  char   *str;
  int    i;
  int    count;
};

/*
** Core functions
*/
int	my_putchar(char c);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	my_power_rec(int nb, int power);
char    *b_strdup(char *str);
char	*my_strupcase(char *);
char	*my_strlowcase(char *);
char	*my_strcapitalize(char *);
int	my_str_islower(char *);
int	my_str_isupper(char *);
int	my_str_isprintable(char *);
char	*my_strcat(char *, char *);
char	*my_strncat(char *, char *, int);
int	my_strlcat(char *, char *, int);
int	free_tab(char **);
int	my_puttab(char **);

/*
** Totab
*/
int	my_char_is_alpha(char);
int	my_char_is_num(char);
char	*old_epure_str(char *);
char	*epure_str(char *);
int	count_word(char *);
void    tronque_str(char *, int, int);
char	*get_new_word(int, char *);
char	**totab(char *, char *);
int	is_sep(char, char *);

/*
** Match
*/
int     match(char *, char *);

/*
** Syscall
*/
void	*my_calloc(int, char);
void	my_memset(char *, char, int);
char	*my_strchr(char *, int);

/*
** GetNextLine
*/

void    tronque(char [], int, int);
char	*get_next_line(const int fd);
void	*traitement(t_get *, const int);
char	*my_realloc(char *, int);

#endif
