#include <42sh.h>

int		my_check_ambigus(t_token *t)
{
  int		nb[2];

  nb[0] = 0;
  nb[1] = 0;
  while (t != NULL && t->id > 2)
    {
      t->id == 3 || t->id == 4 ? (nb[0]++) : 0;
      t->id == 5 || t->id == 6 ? (nb[1]++) : 0;
      t = t->next;
    }
  nb[0] > 1 || nb[1] > 1 ? printf("Ambiguous output redirect.\n") : 0;
  return (nb[0] > 1 || nb[1] > 1 ? -1 : 0);
}

int		my_execption_p(t_token **t, t_redi *r)
{
  r->type = 1;
  r->id = (*t)->id;
  (*t) = (*t)->next;
  if (*t != NULL)
    {
      my_firstwordget(&(r->file), &(r->argv), (*t)->str);
      *t = (*t)->next;
    }
  return (-1);
}

int		my_stand_p(t_token **t, t_redi *r)
{
  int		i;

  i = 0;
  r->type = 0;
  r->argv = (*t)->str;
  (*t) = (*t)->next;
  if ((*t) != NULL)
    {
      r->id = (*t)->id;
      ((*t) = (*t)->next);
      if ((*t) != NULL)
	{
	  while ((*t)->str != NULL && (*t)->str[i] == ' ')
	    i++;
	  r->file = ((*t)->str[i] != 0 ? &((*t)->str[i]) : NULL);
	  (*t) != NULL ? ((*t) = (*t)->next) : 0;
	}
    }
  return (0);
}

int		my_parse_red(t_redi *red, t_token *t)
{
  void		*save;

  save = red;
  while (t != NULL && t->id > 2)
    {
      t->id != 7 ? my_execption_p(&t, red) : my_stand_p(&t, red);
      if ((red->next = malloc(sizeof(t_redi))) == NULL &&
	  printf("Error with Malloc in my_parse_red\n") >= 0)
	return (-1);
      save = red;
      red = red->next;
    }
  red != NULL ? free(red) : 0;
  red = save;
  red->next = NULL;
  return (0);
}

int		my_redir(t_token *t, char **env, t_utils *ut)
{
  t_redi	*redi;
  int		exec;

  if (my_check_ambigus(t) == -1)
    return (-1);
  if ((t != NULL && t->id == 7 && t->next != NULL && t->next->id > 2)
      || (t != NULL && t->id > 2 && t->next != NULL && t->next->id == 7))
    {
      if ((redi = malloc(sizeof(t_redi))) == NULL &&
	  printf("Error with Malloc in my_redir\n") >= 0)
	return (-1);
      redi->id = 7;
      redi->file = NULL;
      redi->argv = NULL;
      redi->next = NULL;
      my_parse_red(redi, t);
      exec = my_handle_red(redi, env, ut);
      my_free_3(redi);
      return (exec);
    }
  return (execute(t->str, env, ut));
}
