/*
** my_strlen.c for  in /home/chahi_y/rendu/Piscine-C-Jour_04
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Thu Oct  3 14:57:47 2013 chahi
** Last update Wed May  7 12:07:39 2014 chahi
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  if (!str)
    return (0);
  while (str[++i]);
  return (i);
}

int	my_strstrlen(char **tab)
{
  int	i;

  i = 0;
  if (!tab)
    return (0);
  while (tab[i++]);
  return (i);
}
