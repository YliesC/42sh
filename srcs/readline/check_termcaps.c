#include "my_readline.h"

int	check_term(t_term *term)
{
  char  buff[120];
  int   len;
  int   stop;

  stop = 0;
  if (term->term != NULL)
    if (tgetent(NULL, term->term) == 1)
      stop = 1;
  while (term->term == NULL || stop == 0)
    {
      my_putstr("\033c");
      my_putstr("TERM variable was not found. Enter a term name : ");
      if ((len = read(0, buff, 119)) < 0)
	return (-1);
      buff[len - 1] = 0;
      if (tgetent(NULL, buff) == 1)
	{
	  term->term = b_strdup(buff);
	  stop = 1;
	}
      my_putstr("\033c");
    }
  return (0);
}

int	check_tgetent(int x)
{
  if (x < 0)
    {
      printf(E_ENTA);
      return (-1);
    }
  if (x == 0)
    {
      printf(E_ENTB);
      return (-1);
    }
  return (1);
}
