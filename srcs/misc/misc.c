#include <42sh.h>

char	*get_env_var(t_utils *utils, char *var)
{
  t_env	*tmp;

  tmp = utils->env;
  while (tmp && tmp->next != utils->env)
    {
      if (match(var, tmp->key))
	{
	  return (tmp->value);
	}
      tmp = tmp->next;
    }
  if (tmp && match(var, tmp->key))
    return (tmp->value);
  return (NULL);
}

char	*set_env_var(t_utils *utils, char *key, char *value)
{
  t_env	*tmp;

  tmp = utils->env;
  while (tmp && tmp->next != utils->env)
    {
      if (match(key, tmp->key))
	{
	  tmp->value = value;
	  return (tmp->value);
	}
      tmp = tmp->next;
    }
  if (match(key, tmp->key))
    {
      tmp->value = value;
      return (tmp->value);
    }
  return (NULL);
}

char	*fill_env_i()
{
  char	*path;
  int	fd;
  int	len;

  if ((path = malloc(sizeof (char) * 4096)) == NULL)
    return (NULL);
  if ((fd = open(PATH_FILE, O_RDONLY)) == -1)
    return (NULL);
  if ((len = read(fd, path, 4096)) == -1)
    return (NULL);
  if (close(fd) == -1)
    return (NULL);
  path[len] = 0;
  return (path);
}

int    print_error(char *err)
{
  write(2, "\033[31m[Error]\033[0m ", my_strlen("\033[31m[Error]\033[0m "));
  write(2, err, my_strlen(err));
  write(2, "\n", 1);
  return (EXIT_FAILURE);
}
