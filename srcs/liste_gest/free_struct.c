#include <42sh.h>

int		free_env(t_env *env)
{
  t_env		*tmp;
  t_env		*save;

  tmp = env;
  while (tmp && tmp->next != env)
    {
      save = tmp->next;
      remove_elem_env(&tmp, &env);
      tmp = save;
    }
  if (tmp)
    remove_elem_env(&tmp, &env);
  return (0);
}

int		free_history(t_history *history)
{
  t_history	*tmp;
  t_history	*save;

  tmp = history;
  while (tmp && tmp->next != history)
    {
      save = tmp->next;
      remove_elem_history(&tmp, &history);
      tmp = save;
    }
  if (tmp)
    remove_elem_history(&tmp, &history);
  return (0);
}

int		free_alias(t_alias *alias)
{
  t_alias	*tmp;
  t_alias	*save;

  tmp = alias;
  while (tmp && tmp->next != alias)
    {
      save = tmp->next;
      remove_elem_alias(&tmp, &alias);
      tmp = save;
    }
  if (tmp)
    remove_elem_alias(&tmp, &alias);
  return (0);
}

int	free_struct(t_base *base)
{
  if (base && base->token == 0)
    free_env((t_env *)base);
  else if (base && base->token == 1)
    free_history((t_history *)base);
  return (0);
}
