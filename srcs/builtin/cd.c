#include <42sh.h>

int	go_to_old(t_utils *utils)
{
  char	*old_pwd;
  char	*pwd;

  if ((old_pwd = get_env_var(utils, "OLDPWD")) == NULL)
    return (EXIT_FAILURE);
  if (chdir(old_pwd) == -1)
    return (EXIT_FAILURE);
  if ((pwd = get_env_var(utils, "PWD")) == NULL)
    return (EXIT_FAILURE);
  set_env_var(utils, "OLDPWD", pwd);
  set_env_var(utils, "PWD", old_pwd);
  printf("%s\n", pwd);
  return (EXIT_SUCCESS);
}

int	go_to_new(t_utils *utils)
{
  char	*pwd;
  char	*new_pwd;

  if ((pwd = get_env_var(utils, "PWD")) == NULL)
    return (EXIT_FAILURE);
  if ((new_pwd = getcwd(NULL, 0)) == NULL)
    {
      printf("%m\n");
      return (EXIT_FAILURE);
    }
  set_env_var(utils, "OLDPWD", pwd);
  set_env_var(utils, "PWD", new_pwd);
  return (EXIT_SUCCESS);
}

int	go_to_home(t_utils *utils)
{
  char	*home;
  char	*pwd;

  if ((home = get_env_var(utils, "HOME")) == NULL)
    return (EXIT_FAILURE);
  if ((pwd = get_env_var(utils, "PWD")) == NULL)
    return (EXIT_FAILURE);
  set_env_var(utils, "OLDPWD", pwd);
  set_env_var(utils, "PWD", home);
  return (EXIT_SUCCESS);
}

int	__cd(char **args, t_utils *utils)
{
  int	ret;

  ret = EXIT_SUCCESS;
  if (args[0] && !args[1] && match(args[0], "cd"))
    ret = go_to_home(utils);
  else if (args[1] && match(args[1], "-"))
    ret = go_to_old(utils);
  else
    {
      if (args[1])
	{
	  if (chdir(args[1]) == -1)
	    {
	      printf("%s: %m\n", args[1]);
	      return (EXIT_FAILURE);
	    }
	  else
	    ret = go_to_new(utils);
	}
    }
  return (ret);
}
