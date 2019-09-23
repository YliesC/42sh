#include "my_readline.h"

void		my_begin(int limit[2])
{
  char          curs[3];

  curs[0] = 27;
  curs[1] = 91;
  curs[2] = 68;
  while (limit[0] > 0)
    {
      write(1, curs, 3);
      limit[0]--;
    }
}

void		my_stringend(int limit[2])
{
  char          curs[3];

  curs[0] = 27;
  curs[1] = 91;
  curs[2] = 67;
  while (limit[0] < limit[1])
    {
      write(1, curs, 3);
      limit[0]++;
    }
}

void		my_clear(char *str, int limit, char *prompt)
{
  write(1, "\033c", my_strlen("\033c"));
  write(1, prompt, my_strlen(prompt));
  write(1, str, limit);
}

void		my_cut(int limit[2], char *str, char *save, char *prompt)
{
  int		a;
  int		b;

  a = limit[0];
  b = 0;
  while (a < limit[1])
    {
      save[b] = str[a];
      b++;
      a++;
    }
  save[b] = '\0';
  write(1, "\r", 1);
  write(1, prompt, my_strlen(prompt));
  write(1, str, limit[0]);
  a = limit[1];
  while (limit[1] > limit[0])
    {
      write(1, " ", 1);
      limit[1]--;
    }
  str[limit[1]] = '\0';
  put_back_curs(limit[0], a);
}

void		my_paste(char *str, char *save, int limit[2], char *prompt)
{
  int		b;

  b = 0;
  while (limit[0] < (limit[1] + my_strlen(save)) && limit[0] < 2047)
    {
      str[limit[0]] = save[b];
      b++;
      limit[0]++;
    }
  write(1, "\r", 1);
  write(1, prompt, my_strlen(prompt));
  write(1, str, limit[0]);
  limit[1] = limit[0];
  str[limit[1]] = '\0';
  my_stringend(limit);
}
