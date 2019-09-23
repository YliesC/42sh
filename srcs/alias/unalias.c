#include <42sh.h>

int	matching_unalias(t_alias *tmp, char *shortkey, t_utils *utils)
{
  if (tmp && tmp->shortkey && match(tmp->shortkey, shortkey))
    {
      my_putstr("\033[32m[Success]\033[0m Variable \033[33m");
      my_putstr(tmp->shortkey);
      my_putstr("\033[0m was succesfully removed !\n");
      remove_elem_alias(&tmp, &(utils->alias));
    }
  return (0);
}

int		__unalias(char **args, t_utils *utils)
{
  t_alias	*tmp;
  t_alias	*save;

  tmp = utils->alias;
  if (args[1] && my_strlen(args[1]) <= 0)
    {
      print_error("Usage: unalias shortkey");
      return (EXIT_FAILURE);
    }
  while (tmp && tmp->next != utils->alias)
    {
      matching_unalias(tmp, args[1], utils);
      save = tmp->next;
      tmp = save;
    }
  matching_unalias(tmp, args[1], utils);
  return (EXIT_SUCCESS);
}
