#include "my_readline.h"

int	my_strlen(char	*str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    a++;
  return (a);
}

char	*my_strxcpy(char *dest, char *src, char c)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (src[a] != c)
    a++;
  a++;
  while (src[a] != '\0')
    {
      dest[b] = src[a];
      b++;
      a++;
    }
  dest[b] = '\0';
  return (dest);
}

void	my_strcpy_read(int curs, int limit, char *str, char l)
{
  char	c;

  c = str[curs];
  str[curs] = l;
  curs++;
  l = str[curs];
  str[curs] = c;
  c = l;
  curs++;
  while (curs <= limit)
    {
      l = str[curs];
      str[curs] = c;
      c = l;
      curs++;
    }
}
