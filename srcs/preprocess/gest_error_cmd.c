#include <42sh.h>

int	check_nb_token(char *str)
{
  int	nb_sep;

  if ((nb_sep = count_sep(str, '&')) > 2)
    return (-print_error("syntax error near unexpected token `&'"));
  else if ((nb_sep = count_sep(str, '|')) > 2)
    return (-print_error("syntax error near unexpected token `|'"));
  else if ((nb_sep = count_sep(str, '<')) > 2)
    return (-print_error("syntax error near unexpected token `<'"));
  else if ((nb_sep = count_sep(str, '>')) > 2)
    return (-print_error("syntax error near unexpected token `>'"));
  return (1);
}

int	check_first_token(char *str)
{
  if (str[0] == '&')
    return (-print_error("syntax error near unexpected token `&'"));
  else if (str[0] == '|')
    return (-print_error("syntax error near unexpected token `|'"));
  return (1);
}

int	check_double_token(char **cmd)
{
  int	i;

  i = -1;
  while (cmd && cmd[++i])
    if (contain_sep(cmd[i]) && contain_sep(cmd[i + 1]))
      return (-print_error("syntax error"));
  return (1);
}

int	check_error_token(char *str)
{
  char	**__tab;
  int	i;

  i = -1;
  epure_str(str);
  if ((__tab = totab(str, " ")) == NULL)
    return (0);
  if (__tab && __tab[0] && check_first_token(__tab[0]) == -1)
    return (0);
  if (__tab && check_double_token(__tab) == -1)
    return (0);
  while (__tab && __tab[++i])
    {
      if (check_nb_token(__tab[i]) == -1)
	return (0);
    }
  free_tab(__tab);
  return (1);
}
