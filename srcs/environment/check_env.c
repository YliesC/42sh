#include <42sh.h>

int	check_env(t_utils *utils, char **env)
{
  char	*path;

  if (env && env[0])
    fill_env(utils, env);
  else
    {
      if ((path = fill_env_i()))
      	{
	  add_elem_env(&(utils->env), b_strdup("PATH"), b_strdup(path));
     	  utils->path = totab(path, ":");
	  free(path);
      	}
      else
      	print_error("Cannot access env-vars. Somes commands will not work.");
    }
  if (get_path(utils) == -1)
    return (-1);
  return (0);
}
