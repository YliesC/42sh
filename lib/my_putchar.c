/*
** my_putchar.c for  in /home/chahi_y/Desktop/my
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Fri Oct 11 09:29:56 2013 chahi
** Last update Mon Apr 14 14:55:31 2014 chahi
*/

#include <my.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}
