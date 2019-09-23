#include <42sh.h>

int	is_in_str(char c, char *sep)
{
  int	i;

  i = -1;
  while (sep && sep[++i])
    if (c == sep[i])
      return (i);
  return (-1);
}

int	get_option(char *last_opt, t_echo *echo)
{
  if (last_opt && !match(last_opt, "echo"))
    {
      if (match(last_opt, "-e"))
	echo->e_flag = 1;
      else if (match(last_opt, "-E"))
	echo->E_flag = 1;
      else if (match(last_opt, "-n"))
	echo->n_flag = 1;
      return (1);
    }
  else
    return (0);
  return (-1);
}

int	get_output(char **args, t_echo *echo)
{
  int	i;
  char	flag;

  flag = 1;
  i = 0;
  while (args && args[++i] && flag)
    {
      if (!match(args[i], "-*"))
	{
	  flag = 0;
	  echo->output = i;
	}
    }
  if (i > 2)
    get_option(args[i - 2], echo);
  if (args && !args[1])
    printf("\n");
  return (0);
}

void	init_echo(t_echo *echo)
{
  echo->e_flag = 0;
  echo->E_flag = 0;
  echo->n_flag = 0;
  echo->output = 1;
  echo->slash[0] = '\a';
  echo->slash[1] = '\b';
  echo->slash[2] = '\e';
  echo->slash[3] = '\f';
  echo->slash[4] = '\n';
  echo->slash[5] = '\r';
  echo->slash[6] = '\t';
  echo->slash[7] = '\v';
  echo->slash[8] = 0;
  echo->letter[0] = 'a';
  echo->letter[1] = 'b';
  echo->letter[2] = 'e';
  echo->letter[3] = 'f';
  echo->letter[4] = 'n';
  echo->letter[5] = 'r';
  echo->letter[6] = 't';
  echo->letter[7] = 'v';
  echo->letter[8] = 0;
}

int	__echo(char **args, t_utils *utils)
{
  t_echo	echo;

  utils = utils;
  init_echo(&echo);
  get_output(args, &echo);
  if (echo.e_flag)
    option_e(args, &echo);
  else if (echo.E_flag)
    option_upper_e(args, &echo);
  else if (echo.n_flag)
    option_n(args, &echo);
  else
    no_option(args, &echo);
  return (EXIT_SUCCESS);
}
