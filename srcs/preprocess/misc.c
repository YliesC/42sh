#include <42sh.h>

int	count_sep(char *str, char sep)
{
  int	i;
  int	count;

  count = 0;
  i = -1;
  while (str && str[++i])
    if (str[i] == sep)
      count++;
  return (count);
}

int	contain_sep(char *str)
{
  int	i;

  i = -1;
  while (str && str[++i])
    if (is_sep(str[i], "&|"))
      return (1);
  return (0);
}
