#include <42sh.h>

void	init_struct(t_utils *utils)
{
  utils->env = NULL;
  utils->history = NULL;
  utils->alias = NULL;
  utils->path = NULL;
  utils->my_exit = 0;
  utils->last_ret = 0;
}
