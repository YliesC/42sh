#include <42sh.h>

void	add_first(t_base **maillon, t_base **base)
{
  (*base) = (*maillon);
  (*maillon)->prev = (*base);
  (*maillon)->next = (*base);
}

t_base		*add_to_list(t_base **base, int token)
{
  t_base	*maillon;
  t_base	*mp;

  if (token == 0)
    maillon = malloc(sizeof(t_env));
  else if (token == 1)
    maillon = malloc(sizeof(t_history));
  else if (token == 2)
    maillon = malloc(sizeof(t_alias));
  else
    return (NULL);
  if ((*base) == NULL)
    add_first(&maillon, base);
  else
    {
      mp = (*base)->prev;
      maillon->next = (*base);
      (*base)->prev = maillon;
      mp->next = maillon;
      maillon->prev = mp;
    }
  return (maillon);
}
