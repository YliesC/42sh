#include <42sh.h>

static char	*my_check_alias(char *str, t_utils *ut)
{
  t_alias *	tmp;

  tmp = ut->alias;
  while (tmp && tmp->next != ut->alias)
    {
      if (match(str, tmp->shortkey))
	return (b_strdup(tmp->command));
      tmp = tmp->next;
    }
  if (tmp)
    {
      if (match(str, tmp->shortkey))
	return (b_strdup(tmp->command));
    }
  return (NULL);
}

int		my_and_next(double *test, t_token **t)
{
  double	te;

  te = *test;
  my_refull(t);
  te = next_and_or_null(*t);
  while (te != 0 && (te + 0.5) != ((int) (te)) + 1)
    {
      my_refull(t);
      te = next_and_or_null(*t);
    }
  if (te == 0)
    *test = 0;
  else
    my_refull(t);
  return (0);
}

int		my_or_next(double *test, t_token **t)
{
  double	te;

  te = *test;
  my_refull(t);
  te = next_and_or_null(*t);
  while (te != 0 && (te + 0.5) == ((int) (te)) + 1)
    {
      my_refull(t);
      te = next_and_or_null(*t);
    }
  if (te == 0)
    *test = 0;
  else
    my_refull(t);
  return (0);
}

int	my_next(int res, double *test, t_token **t)
{
  if (*test == 0)
    return (0);
  if (res == -1)
    return (my_and_next(test, t));
  if (res == -2)
    return (my_or_next(test, t));
  my_refull(t);
  return (0);
}

int	execute(char *str, char **env, t_utils *ut)
{
  int	ret;
  char	**line;
  char	*newline;
  int	i;

  i = -1;
  line = totab(str, " ");
  replaces_dol_inte(line, ut->last_ret);
  replaces_env_var(line, env);
  while (line && line[++i])
    if ((newline = my_check_alias(line[i], ut)) != NULL)
      line[i] = newline;
  if ((ret = builtin(line[0], line, ut)) > -1)
    return (ret);
  return (my_execute2(line, ut, env));
}
