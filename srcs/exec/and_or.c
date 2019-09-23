#include <42sh.h>

int		my_struclen(t_env *env)
{
  int		i;
  void		*end;

  i = 0;
  end = (env !=  NULL ? env->prev : NULL);
  while (env != NULL && env != end)
    {
      i++;
      env = env->next;
    }
  i++;
  return (i);
}

char		*my_glstr_char(char *frst, char *scnd, char sep)
{
  char		*str;
  int		i[2];

  if (frst == NULL && scnd == NULL)
    return (NULL);
  if (scnd == NULL || frst == NULL)
    return (scnd == NULL ? frst : scnd);

  str = malloc(sizeof(char) * (my_strlen(frst) + my_strlen(scnd) + 2));
  if (str == NULL)
    return (NULL);
  i[0] = 0;
  i[1] = 0;
  while (frst[i[1]] != 0)
    str[i[0]++] = frst[i[1]++];
  str[i[0]++] = sep;
  i[1] = 0;
  while (scnd[i[1]] != 0)
    str[i[0]++] = scnd[i[1]++];
  str[i[0]] = 0;
  return (str);
}

char		**list_to_tab(t_env *env)
{
  char		**my_env;
  void		*save;
  int		len;
  int		i;

  len = my_struclen(env);
  if ((my_env = malloc(sizeof(char *) * (len + 1))) == NULL)
    return (NULL);
  i = 0;
  save = env;
  while (env != NULL && (i == 0 || save != env))
    {
      my_env[i] = my_glstr_char(env->key, env->value, '=');
      i++;
      env = env->next;
    }
  my_env[i] = NULL;
  return (my_env);
}

double		next_and_or_null(t_token *t)
{
  int		i;

  i = 0;
  while (t != NULL && t->id != 0 && t->id != 1)
    {
      t = t->next;
      i++;
    }
  if (t == NULL)
    return (0);
  if (t->id == 0)
    return (i + 0.5);
  return (i);
}

int		and_or(char *str, t_utils *ut)
{
  t_token	*t;
  char		**env;
  void		*save;
  double       	test;
  int		exec;

  my_parse(str, &t);
  if (my_check_token(t) == 1)
    return (1);
  save = t;
  env = (ut->env == NULL ? NULL : list_to_tab(ut->env));
  test = 1;
  while (test != 0)
    {
      test = next_and_or_null(t);
      exec = (t != NULL ? my_pipes(t, env, ut) : 1);
      if (exec == 42)
	return (42);
      my_next(my_continue(exec, &test), &test, &t);
    }
  my_free_2(env, save);
  env != NULL ? free(env) : 0;
  return (exec);
}
