/*
** my_power_rec.c for  in /home/chahi_y/rendu/Piscine-C-Jour_05
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Sun Oct  6 18:18:59 2013 chahi
** Last update Wed May  7 11:20:43 2014 chahi
*/

#include <my.h>

int	my_power_rec(int nb, int power)
{
  int	tmp;

  if (nb == 0 || power < 0)
    return (0);
  if (nb == 1 || power == 0)
    return (1);
  tmp = nb;
  nb = tmp * my_power_rec(nb, power - 1);
  return (nb);
}
