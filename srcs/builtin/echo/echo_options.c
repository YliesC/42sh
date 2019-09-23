#include <42sh.h>

static void	option_e_bis(int i, int j, char **args, t_echo *echo)
{
  int		nb;

  nb = 0;
  while (args[j] && args[j][++i])
    if (args[j][i] == '\\')
      {
	i++;
	if ((nb = is_in_str(args[j][i + 1], echo->letter)) != -1)
	  {
	    i++;
	    write(1, &(echo->slash[nb]), 1);
	  }
	else
	  write(1, &args[j][i], 1);
      }
    else
      write(1, &args[j][i], 1);
  if (args[j + 1] == NULL)
    write(1, "\n", 1);
  else
    write(1, " ", 1);
}

int	option_e(char **args, t_echo *echo)
{
  int	j;

  j = echo->output - 1;
  while (args && args[++j])
    option_e_bis(-1, j, args, echo);
  return (1);
}

int	option_upper_e(char **args, t_echo *echo)
{
  int	j;

  j = echo->output - 1;
  while (args && args[++j])
    {
      my_putstr(args[j]);
      if (args[j + 1] != NULL)
	my_putstr(" ");
    }
  my_putstr("\n");
  return (1);
}

int	option_n(char **args, t_echo *echo)
{
    int	j;

  j = echo->output - 1;
  while (args && args[++j])
    {
      my_putstr(args[j]);
      if (args[j + 1] != NULL)
	my_putstr(" ");
    }
  return (1);
}

int	no_option(char **args, t_echo *echo)
{
  int	j;

  j = echo->output - 1;
  while (args && args[++j])
    {
      my_putstr(args[j]);
      if (args[j + 1] != NULL)
	my_putstr(" ");
    }
  my_putstr("\n");
  return (1);
}
