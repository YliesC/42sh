#include <42sh.h>

static int	remove_quote(char *str)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (str && str[i])
    {
      if (str[i] != '\'')
	str[j++] = str[i++];
      else
	++i;
    }
  str[j] = 0;
  return (0);
}

static int	search_occurence(t_alias *tmp, char *shortkey, char *command)
{
  if (tmp && match(shortkey, tmp->shortkey))
    {
      free(tmp->command);
      if (command != NULL)
	tmp->command = command;
      else
	tmp->command = "";
      return (0);
    }
  return (-1);
}

static int	replace_alias(t_utils *utils, char *shortkey, char *command)
{
  t_alias	*tmp;

  tmp = utils->alias;
  while (tmp && tmp->next != utils->alias)
    {
      if (search_occurence(tmp, shortkey, command) == 0)
	return (0);
      tmp = tmp->next;
    }
  if (search_occurence(tmp, shortkey, command) == 0)
    return (0);
  return (-1);
}

static int	replace_command(t_utils *utils, char *shortkey, char *command)
{
  t_alias	*tmp;

  tmp = utils->alias;
  while (tmp && tmp->next != utils->alias)
    {
      if (match(tmp->shortkey, command))
	{
	  add_elem_alias(&(utils->alias), shortkey, b_strdup(tmp->command));
	  return (1);
	}
      tmp = tmp->next;
    }
  if (tmp && match(tmp->shortkey, command))
    {
      add_elem_alias(&(utils->alias), shortkey, b_strdup(tmp->command));
      return (1);
    }
  return (-1);
}

int	__alias(char **args, t_utils *utils)
{
  char	**__tab;

  if (args[1] && match(args[1], "*=\'*\'"))
    {
      if ((__tab = totab(args[1], "=")) == NULL)
	return (EXIT_FAILURE);
      if (__tab && __tab[1])
	{
	  remove_quote(__tab[1]);
	  if (replace_alias(utils, __tab[0], __tab[1]) == -1)
	    if (replace_command(utils, __tab[0], __tab[1]) == -1)
	      add_elem_alias(&(utils->alias), __tab[0], __tab[1]);
	}
      my_putstr("\033[32m[Success]\033[0m Variable \033[33m");
      my_putstr(__tab[0]);
      my_putstr("\033[0m was succesfully added !\n");
    }
  else
    {
      print_error("Usage: alias shortkey='command'");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
