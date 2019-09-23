/*
** my_tronque.c for my_tronque in /home/chahi_y/lib/libmy
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Fri Nov 22 19:17:29 2013 chahi
** Last update Mon Apr 14 14:52:52 2014 chahi
*/

void	tronque(char tab[], int j, int n)
{
  int	i;

  i = -1;
  while (++i < n)
    tab[i] = tab[i + j];
  tab[n] = 0;
}
