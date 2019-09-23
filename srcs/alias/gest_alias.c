#include <42sh.h>

int		add_elem_alias(t_alias **list, char *shortkey, char *command)
{
  static t_base	*last;

  last = add_to_list((t_base **)list, 2);
  ((t_alias *)last)->token = 2;
  ((t_alias *)last)->shortkey = shortkey;
  ((t_alias *)last)->command = command;
  return (0);
}

int	remove_elem_alias(t_alias **maillon, t_alias **first)
{
  if ((*maillon) && (*maillon)->next != (*maillon) &&
      (*maillon)->prev != (*maillon))
    {
      if ((*maillon) == (*first))
	(*first) = (*first)->next;
      (*maillon)->prev->next = (*maillon)->next;
      (*maillon)->next->prev = (*maillon)->prev;
      if ((*maillon)->shortkey)
	free((*maillon)->shortkey);
      if ((*maillon)->command)
	free((*maillon)->command);
      free((*maillon));
    }
  else
    {
      if ((*maillon)->shortkey)
	free((*maillon)->shortkey);
      if ((*maillon)->command)
	free((*maillon)->command);
      free((*maillon));
      (*first) = NULL;
    }
  return (0);
}
