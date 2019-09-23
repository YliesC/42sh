/*
** syscall.c for libmy in /home/chahi_y/lib/libmy
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Mon May 12 00:28:31 2014 chahi
** Last update Mon May 12 00:55:12 2014 chahi
*/

#include <my.h>

char	*my_realloc(char *str, int size)
{
  char	*result;
  int	len;

  if (str)
    result = str;
  len = my_strlen(result);
  if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  str[0] = 0;
  my_strncat(str, result, len);
  str[size] = 0;
  return (str);
}

void	*my_calloc(int size, char c)
{
  char	*str;
  int	i;

  i = 0;
  if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
    return (NULL);
  while (i < size)
    str[i++] = c;
  str[size] = 0;
  return (str);
}

void	my_memset(char *str, char c, int len)
{
  int	i;

  i = 0;
  while (i < len)
    str[i++] = c;
}
