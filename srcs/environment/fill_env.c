#include <42sh.h>

int		fill_env(t_utils *utils, char **env)
{
  int		i;
  char		**__tab;
  static t_base	*last;

  i = -1;
  if (env == NULL)
    return (-1);
  while (env && env[++i])
    {
      if ((__tab = totab(env[i], "=")) == NULL)
	return (-1);
      last = add_to_list((t_base **)&(utils->env), 0);
      ((t_env *)last)->token = 0;
      ((t_env *)last)->key = NULL;
      ((t_env *)last)->value = b_strdup("");
      if (__tab[0])
	((t_env *)last)->key = b_strdup(__tab[0]);
      if (__tab[1])
	{
	  free(((t_env *)last)->value);
	  ((t_env *)last)->value = b_strdup(__tab[1]);
	}
      free_tab(__tab);
    }
  return (0);
}
