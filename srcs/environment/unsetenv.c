#include <42sh.h>

static int	matching_unsetenv(t_env *tmp, char *key, t_utils *utils)
{
  if (match(tmp->key, key))
    {
      my_putstr("\033[32m[Success]\033[0m Variable \033[33m");
      my_putstr(tmp->key);
      my_putstr("\033[0m was succesfully removed !\n");
      remove_elem_env(&tmp, &(utils->env));
    }
  return (0);
}

int	__unsetenv(char **args, t_utils *utils)
{
  t_env	*tmp;
  t_env	*save;

  tmp = utils->env;
  if (args == NULL || args[0] == NULL || args[1] == NULL
      || my_strlen(args[1]) <= 0)
    {
      print_error("Usage: unsetenv KEY");
      return (EXIT_FAILURE);
    }
  while (tmp && tmp->next != utils->env)
    {
      matching_unsetenv(tmp, args[1], utils);
      save = tmp->next;
      tmp = save;
    }
  if (tmp != NULL)
    matching_unsetenv(tmp, args[1], utils);
  return (EXIT_SUCCESS);
}
