/*
** my_strdup.c for  in /home/chahi_y/rendu/Piscine-C-Jour_08
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Wed Oct  9 09:03:13 2013 chahi
** Last update Sun May 25 16:58:39 2014 chahi
*/

#include <my.h>

char	*b_strdup(char *str)
{
  char	*new_str;
  int   i;

  if ((new_str = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = -1;
  while (str[++i])
    new_str[i] = str[i];
  new_str[i] = 0;
  return (new_str);
}
