#include "my_readline.h"

static void	print_space(int a, int b)
{
  int		i;
  int		nb;
  char		cmd[3];

  cmd[0] = 27;
  cmd[1] = 91;
  cmd[2] = LEFT;
  i = -1;
  if ((nb = (a - b)) > 0)
    {
      while (++i < nb)
	write(1, " ", 1);
      i = -1;
      while (++i < nb)
	write(1, cmd, 3);
    }
}

static void	my_write(char *prompt, t_data *data)
{
  write(1, "\r", 1);
  write(1, prompt, my_strlen(prompt) + 1);
  write(1, data->str, my_strlen(data->str));
}

void	my_history(t_data *data, t_history *history, char *prompt, int *flag)
{
  static t_history	*tmp;
  int			len;

  len = my_strlen(data->str);
  if (*flag)
    {
      if ((tmp = history) == NULL)
	return ;
      *flag = 0;
    }
  if (data->letter[2] == DOWN)
    {
      tmp = tmp->next;
      strcpy(data->str, tmp->str);
    }
  else if (data->letter[2] == UP)
    {
      tmp = tmp->prev;
      strcpy(data->str, tmp->str);
    }
  my_write(prompt, data);
  print_space(len, my_strlen(data->str));
  data->limit[1] = my_strlen(data->str);
  data->limit[0] = my_strlen(data->str);
}
