#include "my_readline.h"

void		my_erase(char *str, int limit[2], char *prompt)
{
  int		a;

  a = limit[0] - 1;
  if (limit[0] > 0)
    {
      while (a < (limit[1] - 1))
	{
	  str[a] = str[a + 1];
	  a++;
	}
      limit[1]--;
      limit[0]--;
      prompt=prompt;
      write(1, "\r", 1);
      write(1, prompt, my_strlen(prompt));
      write(1, str, limit[1]);
      write(1, " ", 1);
      put_back_curs(limit[0], limit[1] + 1);
    }
}

void		put_back_curs(int limit, int a)
{
  int		b;
  char		curs[3];

  b = 0;
  curs[0] = 27;
  curs[1] = 91;
  curs[2] = 68;
  while (b < (a - limit))
    {
      write(1, curs, 3);
      b++;
    }
}

void		put_char(int limit[2], char *str, char *letter, char *prompt)
{
  if (limit[0] < limit[1])
    {
      my_strcpy_read(limit[0], limit[1], str, letter[0]);
      write(1, "\r", 1);
      write(1, prompt, my_strlen(prompt));
      limit[0]++;
      limit[1]++;
      write(1, str, limit[1]);
      put_back_curs(limit[0], limit[1]);
    }
  else
    {
      str[limit[1]] = letter[0];
      write(1, "\r", 1);
      write(1, prompt, my_strlen(prompt));
      limit[0]++;
      limit[1]++;
      write(1, str, limit[1]);
    }
}

char		*my_end(int limit, char *str)
{
  write(1, "\n", 1);
  str[limit] = '\0';
  return (str);
}

int		move_cursor(int a, int limit, char *letter)
{
  if (letter[2] == 67 && a < limit)
    {
      a++;
      write(1, letter, 3);
    }
  if (letter[2] == 68 && a > 0)
    {
      a--;
      write(1, letter, 3);
    }
  return (a);
}
