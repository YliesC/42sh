#include <42sh.h>

int	__env(char **args, t_utils *utils)
{
  args = args;
  print_liste((t_base *)utils->env);
  return (EXIT_SUCCESS);
}
