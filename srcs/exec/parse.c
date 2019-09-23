#include <42sh.h>

int		my_isinstr(char *str, char *op)
{
  int		i;

  i = 0;
  if (str == NULL || op == NULL)
    return (0);
  while (str[i] != 0 && op[i] != 0)
    {
      if (op[i] != str[i])
	return (0);
      i++;
    }
  if (op[i] == 0)
    return (1);
  return (0);
}

int		my_next_word(char *str, char *op[8], int i[2])
{
  int		j;

  if (str == NULL || str[i[0]] == 0)
    return (-1);
  while (str != NULL && (str[i[0]] == ' ' || str[i[0]] == '\t'))
    i[0]++;
  i[1] = i[0];
  while (str[i[1]] != 0)
    {
      j = 0;
      while (op[j] != NULL && my_isinstr(&str[i[1]], op[j]) == 0)
	j++;
      if (op[j] != NULL && i[1] == i[0])
	return (i[1] += my_strlen(op[j]));
      if (op[j] != NULL)
	return (0);
      i[1]++;
    }
  return (0);
}

int		my_fullfil_str(char *or, char *ds, int end)
{
  int		i;

  i = 0;
  if (or == NULL || ds == NULL)
    return (-1);
  while (i < end)
    {
      ds[i] = or[i];
      i++;
    }
  ds[i] = 0;
  return (0);
}

int		my_parse_t(t_token *t, char *str, char *op[8])
{
  int		i[2];
  void		*save;

  i[0] = 0;
  i[1] = 0;
  save = NULL;
  while (my_next_word(str, op, i) != -1)
    {
      if ((t->str = malloc(sizeof(char) * (i[1] - i[0] + 1))) == NULL)
	return (-1);
      if ((t->next = malloc(sizeof(t_token))) == NULL)
	return (-1);
      my_fullfil_str(&str[i[0]], t->str, i[1] - i[0]);
      epure_str(t->str);
      t->id = my_id_str(t->str);
      i[0] = i[1];
      save = t;
      t = t->next;
    }
  free(t);
  t = save;
  t != NULL ? (t->next = NULL) : 0;
  return (0);
}

int		my_parse(char *str, t_token **t)
{
  char		*op[8];

  if (((*t) = malloc(sizeof(t_token))) == NULL)
    return (-1);
  op[0] = "||";
  op[1] = "&&";
  op[2] = "|";
  op[3] = "<<";
  op[4] = "<";
  op[5] = ">>";
  op[6] = ">";
  op[7] = NULL;
  my_parse_t(*t, str, op);
  return (0);
}
