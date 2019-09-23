/*
** my_putstr.c for  in /home/chahi_y/rendu/Piscine-C-Jour_04
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Thu Oct  3 14:58:16 2013 chahi
** Last update Wed May  7 12:04:39 2014 chahi
*/

#include <my.h>

int	my_putstr(char *str)
{
  while (*str)
    my_putchar(*str++);
  return (0);
}

int	my_puttab(char **tab)
{
  int	i;

  i = -1;
  while (tab && tab[++i])
    {
      my_putstr(tab[i]);
      my_putchar('\n');
    }
  return (0);
}

int     my_putstr_file(int fd, char *str)
{
  while (*str)
    write(fd, str++, 1);
  return (0);
}
