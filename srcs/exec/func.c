#include <42sh.h>

int	my_strcmp(char *str, char *str2)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str2[i] != '\0')
    {
      if (str[i] == str2[i])
	i++;
      else
	return (0);
    }
  return (1);
}

char	*my_env_fvar(char **env, char *var)
{
  int	i;
  int	i2;
  int	i3;
  char	*str;

  i = 0;
  i2 = 0;
  i3 = 0;
  if (env == NULL && !env[0])
    return (NULL);
  while (env && env[i] && my_strcmp(env[i], var) != 1)
    i++;
  while (env && env[i] && env[i][i2++] != '=');
  if ((str = malloc(sizeof(char) * my_strlen(env[i]))) == NULL)
    return (NULL);
  while (env && env[i] && env[i][i2] != 0)
    str[i3++] = env[i][i2++];
  str[i3] = 0;
  return (str);
}

char	*my_stradder(char *str, char *str2)
{
  char	*new_str;
  int	i;
  int	i2;

  i = -1;
  i2 = 0;
  if (!str || !str2)
    return (NULL);
  if ((new_str = malloc(sizeof(char) *
			(my_strlen(str) + my_strlen(str2) + 2))) == NULL)
    return (NULL);
  while (str[++i] != 0)
    new_str[i] = str[i];
  new_str[i++] = '/';
  while (str2[i2] != 0)
    new_str[i++] = str2[i2++];
  new_str[i] = 0;
  return (new_str);
}

char	*my_exec_create(char *str, char **path_tab)
{
  int	i;
  char	*exec_path;

  i = 0;
  if (!access(str, F_OK) && !access(str, X_OK))
    return (str);
  else
    {
      while (path_tab && path_tab[i] != NULL)
	{
	  if ((exec_path = my_stradder(path_tab[i], str)) == NULL)
	    return (NULL);
	  if (!access(exec_path, F_OK) && !access(exec_path, X_OK))
	    return (exec_path);
	  else
	    ++i;
	  free(exec_path);
	}
      return (str);
    }
}
