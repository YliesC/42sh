#include "my_readline.h"

char			*what_key_bis(t_data *data, char *prompt,
				  t_history *history, int *flag)
{
  if (data->letter[0] == 27 && (data->letter[2] == DOWN ||
				data->letter[2] == UP) && data->ir == 3)
    my_history(data, history, prompt, flag);
  else if (data->letter[0] >= 32 && data->letter[0] <= 126 && data->ir == 1)
    put_char(data->limit, data->str, data->letter, prompt);
  else if (data->letter[0] == 25 && data->ir == 1)
    my_paste(data->str, data->save, data->limit, prompt);
  return (NULL);
}

char			*what_key(t_data *data, char *prompt,
				  t_history *history, int *flag)
{
  if (data->limit[1] < 2047)
    what_key_bis(data, prompt, history, flag);
  if (data->letter[0] == '\n')
    return (my_end(data->limit[1], data->str));
  else if (data->letter[0] == 27 && (data->letter[2] == 67 ||
				     data->letter[2] == 68) && data->ir == 3)
    data->limit[0] = move_cursor(data->limit[0], data->limit[1], data->letter);
  else if ((data->letter[0] == 127 || data->letter[0] == 8) && data->ir == 1)
    my_erase(data->str, data->limit, prompt);
  else if ((data->letter[0] == 1 && data->ir == 1) ||
	   (data->letter[2] == 72 && data->ir == 3))
    my_begin(data->limit);
  else if (data->letter[0] == 12 && data->ir == 1)
    my_clear(data->str, data->limit[1], prompt);
  else if (data->letter[0] == 11 && data->ir == 1)
    my_cut(data->limit, data->str, data->save, prompt);
  else if ((data->letter[0] == 5 && data->ir == 1) ||
	   (data->letter[3] = 70 && data->ir == 3))
    my_stringend(data->limit);
  return (NULL);
}

char			*my_readline(char *prompt, t_utils *utils)
{
  struct termios	termios;
  t_data		*data;
  char			*info;
  int		flag = 1;

  if ((data = malloc(sizeof(*data))) == NULL)
    return (NULL);
  if ((data = init_data(data)) == NULL)
    return (NULL);
  if (init_termcaps(&termios, data->term, utils) == -1)
    return (NULL);
  write(1, prompt, my_strlen(prompt));
  while ((data->ir = read(0, data->letter, 6)))
    {
      if (check_things(data, termios) == -1)
	return (NULL);
      if ((info = what_key(data, prompt, utils->history, &flag)) != NULL)
	{
	  empty_all(data, termios);
	  return (info);
	}
    }
  return (NULL);
}
