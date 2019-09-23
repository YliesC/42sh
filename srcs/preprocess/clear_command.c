#include <42sh.h>

char	*clear_command(char *str, int i)
{
  int	j;
  char	flag;
  char	*new_cmd;

  j = 0;
  flag= 1;
  new_cmd = malloc(sizeof(char) * (my_strlen(str) * 2));
  while (str && str[i])
    if (!is_sep(str[i], "&|<>"))
      {
    	if (flag == 0)
    	  new_cmd[j++] = ' ';
    	new_cmd[j++] = str[i++];
    	flag = 1;
      }
    else if (flag && is_sep(str[i], "&|<>"))
      {
    	new_cmd[j++] = ' ';
    	flag = 0;
      }
    else
      new_cmd[j++] = str[i++];
  new_cmd[j] = 0;
  free(str);
  return (new_cmd);
}
