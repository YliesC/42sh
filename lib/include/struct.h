/*
** struct.h for libmy in /home/chahi_y/lib/libmy
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Mon May 12 00:21:33 2014 chahi
** Last update Wed May 21 11:03:17 2014 chahi
*/

#ifndef STRUCT_H_
# define STRUCT_H_

# define CHECK_RETURN(x, y, z) if ((x) == (y)) return (z)
# define READ (1)

/*
** get_next_line.c
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
** t_base (c mod)
*/
/* typedef struct s_base t_base; */
/* struct s_base */
/* { */
/*   int		token; */
/*   struct s_base	*next; */
/*   struct s_base	*prev; */
/* }; */

#endif
