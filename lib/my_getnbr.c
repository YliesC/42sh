/*
** my_getnbr.c for  in /home/chahi_y/rendu/Piscine-C-Jour_04
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Thu Oct  3 14:56:59 2013 chahi
** Last update Mon Apr 14 15:31:20 2014 chahi
*/

#include <my.h>

void	is_neg(char *st, int *ne)
{
  int	i;

  i = 0;
  while (st[i] != '\0' && (st[i] == '-' || st[i] == '+'))
    {
      if (st[i] == '-')
	*ne = *ne * (-1);
      i = i + 1;
    }
}

void	is_number(char *str, int *taille, int *result, int *ji)
{
  int	i;

  i = 0;
  while ((str[i] >= '0' && str[i] <= '9') || *result != 1)
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  *taille = *taille + 1;
	  *result = 1;
	}
      else
	*ji = *ji + 1;
      i = i + 1;
    }
}

void	calculs(int *taille, char *str, int *ji, long *output)
{
  int	i;
  int	a;

  a = 1;
  i = 0;
  while (i < *taille)
    {
      a = str[*ji + *taille - i - 1] - 48;
      *output = *output + my_power_rec(10, i) * a;
      i = i + 1;
    }
}

int	my_getnbr(char *str)
{
  int   neg;
  int	ji;
  int	result;
  int 	taille;
  long	output;

  ji = 0;
  result = 0;
  taille = 0;
  output = 0;
  is_number(str, &taille, &result, &ji);
  neg = 1;
  is_neg(str, &neg);
  calculs(&taille, str, &ji, &output);
  output = output * neg;
  if (output <= 2147483647 && output >= -2147483648)
    return (output);
  return (0);
}
