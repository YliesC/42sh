/*
** totab.c for libmy in /home/chahi_y/rendu/PSU_2013_42sh
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Tue May 20 01:49:44 2014 chahi
** Last update Sun May 25 15:51:41 2014 chahi
*/

#include <stdlib.h>

int	is_sep(char c, char *sep)
{
  int	i;

  i = -1;
  while (sep && sep[++i])
    if (c == sep[i])
      return (1);
  return (0);
}

int	my_count_words(char *str, char *sep)
{
  int	i;
  int	wrds;

  i = 0;
  wrds = 0;
  while (str[i] != 0)
    {
      if (is_sep(str[i], sep) && i > 0 && !is_sep(str[i - 1], sep))
	wrds++;
      i++;
    }
  if (i > 0 && !is_sep(str[i - 1], sep))
    wrds++;
  if (i == 0)
    wrds++;
  return (wrds);
}

int	my_word_len(char *str, int place, char *sep)
{
  int	i;

  i = 0;
  while (!is_sep(str[place + i], sep) && str[place + i] != 0)
    i++;
  return (i);
}

int	my_fulfil(char *str, char *dest, int *tab, char *sep)
{
  int	i;
  int	end;

  i = 0;
  end = tab[0] + tab[1];
  while (i < end - tab[0])
    dest[i++] = str[tab[0] + i];
  dest[i] = 0;
  while (str[tab[0]] != '\0' && !is_sep(str[tab[0]], sep))
    tab[0]++;
  while (str[tab[0]] != '\0' && is_sep(str[tab[0]], sep))
    tab[0]++;
  return (0);
}

char	**totab(char *str, char *sep)
{
  int	i;
  int	j[2];
  int	nb_wrds;
  char	**wordtab;

  if (str == NULL || str[0] == 0)
    return (NULL);
  while (is_sep(str[0], sep))
    str = &(str[1]);
  nb_wrds = my_count_words(str, sep);
  if ((wordtab = malloc(sizeof(char *) * (nb_wrds + 1))) == NULL)
    return (NULL);
  i = -1;
  j[0] = 0;
  while (++i < nb_wrds)
    {
      j[1] = my_word_len(str, j[0], sep);
      if ((wordtab[i] = malloc(sizeof(*wordtab) * (j[1] + 1))) == NULL)
	return (wordtab);
      my_fulfil(str, wordtab[i], &(j[0]), sep);
    }
  wordtab[i] = NULL;
  return (wordtab);
}
