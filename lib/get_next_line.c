/*
** Get_next_line.c for GetNextLine in /home/chahi_y/rendu/GetNextLine
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Mon Nov 18 01:27:39 2013 chahi
** Last update Mon May 12 00:58:12 2014 chahi
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <my.h>

void	*traitement(t_get *g, const int fd)
{
  while (g->buff[g->i] != '\n' && g->buff[g->i] != 0)
    if (g->j + 1 == g->len || (g->buff[g->i + 1] == '\n'
			       || g->buff[g->i + 1] < 32))
      {
    	while (g->str[g->count++]);
    	if (g->str)
    	  CHECK_RETURN(g->str = my_realloc(g->str, (g->count + g->i + 1)),
		       NULL, NULL);
	my_strncat(g->str, g->buff, g->i + 1);
	tronque(g->buff, g->i + 1, g->len);
    	++(g->j);
    	g->i = 0;
    	if (g->buff[g->i] == '\n' || g->buff[g->i] < 32)
    	  if (g->buff[g->i] == '\0')
    	    {
    	      if ((g->len = read(fd, g->buff, READ)) == 0)
    		return (g->str);
    	      g->j = 0;
    	    }
      }
    else
      {
    	++(g->j);
    	++(g->i);
      }
}

char		*get_next_line(const int fd)
{
  static t_get	*g;
  static int	k = 0;

  if (k == 0)
    {
      CHECK_RETURN(g = malloc(sizeof(t_get)), NULL, NULL);
      g->j = 0;
      g->len = 0;
    }
  k = 1;
  g->count = 0;
  g->i = 0;
  if (++(g->j) >= g->len)
    {
      CHECK_RETURN(g->len = read(fd, g->buff, READ), 0, NULL);
      g->j = 0;
    }
  if (g->len  <= 0 || READ <= 0)
    return (NULL);
  CHECK_RETURN(g->str = malloc(sizeof(char) * READ + 1), NULL, NULL);
  g->str[0] = '\0';
  g->buff[g->len] = '\0';
  CHECK_RETURN(traitement(g, fd), NULL, NULL);
  tronque(g->buff, 1, g->len - (g->i - 2));
  return (g->str);
}
