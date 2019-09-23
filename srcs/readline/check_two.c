#include "my_readline.h"

int		check_things(t_data *data, struct termios termios)
{
  if (data->ir == 1 && data->letter[0] == 4)
    {
      termios.c_lflag |= (ICANON | ECHO);
      tcsetattr(data->term->fo, TCSADRAIN, &termios);
      free(data->term->buff);
      free(data->term);
      free(data->str);
      free(data->save);
      free(data);
      return (-1);
    }
  return (0);
}
