#include "my_readline.h"

void	empty_all(t_data *data, struct termios termios)
{
  termios.c_lflag |= (ICANON | ECHO);
  tcsetattr(data->term->fo, TCSADRAIN, &termios);
}
