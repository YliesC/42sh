#include <42sh.h>

int	get_path(t_utils *utils)
{
  char	*value_path;

  value_path = get_env_var(utils, "PATH");
  if (utils->path)
    free_tab(utils->path);
  utils->path = totab(value_path, ":");
  return (0);
}
