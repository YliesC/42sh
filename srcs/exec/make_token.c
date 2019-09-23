#include <42sh.h>

int	my_id_str(char *str)
{
  if (str == NULL)
    return (-1);
  if (strcmp(str, "||") == 0)
    return (0);
  if (strcmp(str, "&&") == 0)
    return (1);
  if (strcmp(str, "|") == 0)
    return (2);
  if (strcmp(str, "<<") == 0)
    return (3);
  if (strcmp(str, "<") == 0)
    return (4);
  if (strcmp(str, ">>") == 0)
    return (5);
  if (strcmp(str, ">") == 0)
    return (6);
  return (7);
}

void	my_free_2(char **env, t_token *t)
{
  int	i;
  void	*save;

  i = 0;
  while (env != NULL && env[i] != NULL)
    {
      free(env[i]);
      i++;
    }
  while (t != NULL)
    {
      t->str != NULL ? free(t->str) : 0;
      save = t;
      t != NULL ? (t = t->next) : 0;
      save != NULL ? free(save) : 0;
    }
}

void		my_refull(t_token **t)
{
  while ((*t) != NULL && (*t)->id > 1)
    *t = (*t)->next;
  (*t) != NULL ? ((*t) = (*t)->next) : 0;
}

int	my_continue(int exec, double *test)
{
  int	type;

  if (*test == 0)
    return (0);
  if (((int) (*test + 0.5)) == ((int) (*test)))
    type = 1;
  else
    type = 0;
  if (exec != 0 && type == 1 && *test != 0)
    return (-1);
  if (exec == 0 && type == 0 && *test != 0)
    return (-2);
  return (0);
}
