/*
** math.c for  in /home/chahi_y/rendu/Piscine-C-match-nmatch
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Fri Oct 11 09:53:12 2013 chahi
** Last update Fri Apr 18 15:10:08 2014 chahi
*/

#include <my.h>

int     match(char *s1, char *s2)
{
  int   i;

  if (s1 == NULL || s2 == NULL)
    return (0);
  i = -1;
  if (*s2 == '*')
    {
      if (s2[1] == '\0')
	return (1);
      while (++i < my_strlen(s1))
	if (match(s1 + i, s2 + 1) == 1)
	  return (1);
      return (0);
    }
  else
    {
      if (s1 && (*s1 == '\0' && *s2 == '\0'))
	return (1);
      if (*s1 == *s2)
	return (match(s1 + 1, s2 + 1));
      if ((*s1 == '\0' && *s2 != '\0') || (*s2 == '\0' && *s1 != '\0'))
	return (0);
      return (0);
    }
}
