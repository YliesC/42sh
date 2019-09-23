#include <42sh.h>

int	main_loop(char *buffer, t_utils *utils)
{
  char	**__tab;
  int	i;

  i = -1;
  epure_str(buffer);
  if (my_strlen(buffer) > 0)
    add_elem_history(buffer, utils);
  if ((__tab = totab(buffer, ";")) == NULL)
    return (EXIT_FAILURE);
  while (__tab && __tab[++i])
    {
      epure_str(__tab[i]);
      __tab[i] = clear_command(__tab[i], 0);
      if (check_error_token(__tab[i]) == 0)
	return (EXIT_FAILURE);
      if ((utils->last_ret = and_or(__tab[i], utils)) == 42)
	return (42);
    }
  free_tab(__tab);
  return (EXIT_SUCCESS);
}
