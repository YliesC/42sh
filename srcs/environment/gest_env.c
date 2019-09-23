#include <42sh.h>

int		add_elem_env(t_env **list, char *key, char *value)
{
  static t_base	*last;

  last = add_to_list((t_base **)list, 0);
  ((t_env *)last)->token = 0;
  ((t_env *)last)->key = key;
  ((t_env *)last)->value = value;
  return (0);
}

int	remove_elem_env(t_env **maillon, t_env **first)
{
  if ((*maillon) && (*maillon)->next != (*maillon) &&
      (*maillon)->prev != (*maillon))
    {
      if ((*maillon) == (*first))
	(*first) = (*first)->next;
      (*maillon)->prev->next = (*maillon)->next;
      (*maillon)->next->prev = (*maillon)->prev;
      if ((*maillon)->key)
	free((*maillon)->key);
      if ((*maillon)->value)
	free((*maillon)->value);
      free((*maillon));
    }
  else
    {
      if ((*maillon)->key)
	free((*maillon)->key);
      if ((*maillon)->value)
	free((*maillon)->value);
      free((*maillon));
      (*first) = NULL;
    }
  return (0);
}
