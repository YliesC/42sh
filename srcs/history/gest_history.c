#include <42sh.h>

int		add_elem_history(char *str, t_utils *utils)
{
  static t_base	*last;
  static int	nb = 1;

  last = add_to_list((t_base **)&(utils->history), 1);
  ((t_history *)last)->token = 1;
  ((t_history *)last)->nb = nb++;
  ((t_history *)last)->str = strdup(str);
  return (0);
}

int	remove_elem_history(t_history **maillon, t_history **first)
{
  if ((*maillon) && (*maillon)->next != (*maillon) &&
      (*maillon)->prev != (*maillon))
    {
      if ((*maillon) == (*first))
	(*first) = (*first)->next;
      (*maillon)->prev->next = (*maillon)->next;
      (*maillon)->next->prev = (*maillon)->prev;
      free((*maillon)->str);
      free((*maillon));
    }
   return (0);
}
