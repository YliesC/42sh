/*
** free_tab.c for free_tab in /home/chahi_y/rendu/PSU_2013_42sh/lib
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Wed May  7 11:17:44 2014 chahi
** Last update Wed May  7 11:17:49 2014 chahi
*/

#include <my.h>

int	free_tab(char **tab)
{
  int	i;

  i = -1;
  if (tab)
    {
      while (tab[++i])
	free(tab[i]);
      free(tab);
    }
  return (0);
}
