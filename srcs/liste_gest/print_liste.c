#include <42sh.h>

void		print_elem(t_base *tmp)
{
  t_env		*env;
  t_history	*history;
  t_alias	*alias;

  if (tmp && tmp->token == 0)
    {
      if ((env = (t_env *)tmp))
	printf("%s"ENV_SEPARATOR"%s\n", env->key, env->value);
    }
  else if (tmp && tmp->token == 1)
    {
      if ((history = (t_history *)tmp))
	printf("   %d %s\n", history->nb, history->str);
    }
  else if (tmp && tmp->token == 2)
    {
      if ((alias = (t_alias *)tmp))
	printf("key: [%s] command: [%s]\n", alias->shortkey, alias->command);
    }
}

void		print_liste(t_base *liste)
{
  t_base	*tmp;

  tmp = liste;
  while (tmp && tmp->next != liste)
    {
      print_elem(tmp);
      tmp = tmp->next;
    }
  print_elem(tmp);
}
