/*
** count_word.c for count_word in /home/chahi_y/lib/libmy
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Tue Dec 17 18:37:01 2013 chahi
** Last update Mon May 12 00:30:54 2014 chahi
*/

#include <my.h>

int	my_char_is_alpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}

int	my_char_is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	count_word(char *str)
{
  int	i;
  int	w;

  i = 0;
  w = 0;
  while (str && str[i])
    {
      if (str[i] && my_char_is_alpha(str[i]))
        {
          w++;
          while (str[i] && my_char_is_alpha(str[i++]));
        }
      else
          i++;
    }
  return (w);
}
