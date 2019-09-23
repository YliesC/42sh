/*
** epure_str.c for epure_str in /home/chahi_y/lib/libmy
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Tue Dec 17 18:36:01 2013 chahi
** Last update Sun May 25 20:55:37 2014 chahi
*/

#include <my.h>

char    *old_epure_str(char *str)
{
  int   i;
  int   j;
  int   k;
  char  *final;

  i = 0;
  k = 0;
  j = 0;
  if ((final = malloc(sizeof(char)
		      * (my_strlen(str) + 1))) == NULL || str == NULL)
    return (NULL);
  while (str && str[i])
    {
      if (str[i] > 32)
	{
	  k = 1;
	  final[j++] = str[i];
	}
      else if (str[i] >= 0 && str[i] <= 32 && str[i + 1] > 32 && k == 1 )
	final[j++] = ' ';
      i++;
    }
  final[j] = 0;
  return (final);
}

char	*epure_str(char *str)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (str && str[++i])
    if (str[i] > 32)
      {
  	str[j++] = str[i];
  	if (str[i + 1] <= 32 && str[i + 1] != 0)
	  str[j++] = ' ';
      }
  if (str && str[j - 1] == ' ')
    str[j - 1] = 0;
  else if (str)
    str[j] = 0;
  return (str);
}
