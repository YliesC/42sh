#include "my_readline.h"

char		*my_getenv(char *term)
{
  extern char	**environ;
  int		a;
  int		b;
  char		*str;

  a = 0;
  b = 0;
  while (environ[a] != NULL && term[b] != '\0')
    {
      while (environ[a][b] != term[b] &&
             term[b] != '\0' && environ[a][b] != '\0')
        {
          b = 0;
          a++;
          if (environ[a] == NULL)
            return (NULL);
        }
      if (environ[a][b] == term[b])
        b++;
    }
  if (b == 0)
    return (NULL);
  str = malloc(sizeof(char) * my_strlen(environ[a]));
  str = my_strxcpy(str, environ[a], '=');
  return (str);
}

void	set_getattr(int fo, struct termios *termios)
{
  tcgetattr(fo, termios);
  termios->c_lflag &= ~(ICANON | ECHO);
  termios->c_cc[VTIME] = 0;
  termios->c_cc[VMIN] = 1;
  tcsetattr(fo, TCSADRAIN, termios);
}

int		init_termcaps(struct termios *termios, t_term *term, t_utils *utils)
{
  term->term = NULL;
  if ((term->term = get_env_var(utils, "TERM")) == NULL)
    {
      check_term(term);
      add_elem_env(&(utils->env), b_strdup("TERM"), b_strdup(term->term));
    }
  term->fo = STDIN_FILENO;
  set_getattr(term->fo, termios);
  return (1);
}
