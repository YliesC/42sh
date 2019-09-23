/*
** my_strncat.c for  in /home/chahi_y/rendu/Piscine-C-Jour_07/ex_1
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Wed Oct  9 12:07:07 2013 chahi
** Last update Wed May  7 12:51:02 2014 chahi
*/

#include <my.h>

char    *my_strncat(char *dest, char *src, int nb)
{
  int   i;
  int   len;

  if (nb < 0)
    nb = 0;
  i = 0;
  len = my_strlen(dest);
  while (i < nb && src && src[i])
    dest[len + i] = src[i++];
  dest[len + i] = 0;
  return (dest);
}
