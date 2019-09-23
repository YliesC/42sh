#include <42sh.h>

static int	search_occurence(t_env *tmp, char *key, char *value)
{
  if (tmp && match(key, tmp->key))
    {
      if (value != NULL)
	tmp->value = value;
      else
	tmp->value = "";
      return (0);
    }
  return (-1);
}

static int	replace_env(t_utils *utils, char *key, char *value)
{
  t_env		*tmp;

  tmp = utils->env;
  while (tmp && tmp->next != utils->env)
    {
      if (search_occurence(tmp, key, value) == 0)
	return (0);
      tmp = tmp->next;
    }
  if (search_occurence(tmp, key, value) == 0)
    return (0);
  return (-1);
}

static int	replaces_env_var_bis(char **argv, t_utils *utils)
{
  int		i;
  char		*tmp;

  i = 0;
  while (argv != NULL && argv[i] != NULL)
    {
      if (my_strlen(argv[i]) > 1 && argv[i][0] == '$')
	if ((tmp = get_env_var(utils, &argv[i][1])) != NULL)
	  argv[i] = b_strdup(tmp);
      i++;
    }
  return (0);
}

int	__setenv(char **args, t_utils *utils)
{
  char	**__tab;
  char	flag;

  flag = 1;
  if (args[1] == NULL || args[2])
    return (print_error("Usage: setenv KEY=value"));
  if ((__tab = totab(args[1], "=")) == NULL)
    return (print_error("Usage: setenv KEY=value"));
  replaces_env_var_bis(__tab, utils);
  if (flag && replace_env(utils, __tab[0], __tab[1]) == 0)
    flag = 0;
  if (flag && __tab[1] != NULL)
    flag = add_elem_env(&(utils->env), __tab[0], __tab[1]);
  else if (flag)
    flag = add_elem_env(&(utils->env), __tab[0], b_strdup(""));
  if (flag == 0)
    {
      my_putstr("\033[32m[Success]\033[0m Variable \033[33m");
      my_putstr(__tab[0]);
      my_putstr("\033[0m was succesfully added !\n");
    }
  return (EXIT_SUCCESS);
}
