#include <42sh.h>

int	my_firstwordget(char **file, char **argv, char *str)
{
  int	i;

  i = 0;
  while (str != NULL && str[0] == ' ')
    str = &str[1];
  while (str != NULL && str[i] != 0 && str[i] != ' ')
    i++;
  if ((*file = malloc(sizeof(char) * (i + 1))) == NULL)
    return (-1);
  i = 0;
  while (str != NULL && str[i] != 0 && str[i] != ' ')
    {
      (*file)[i] = str[i];
      i++;
    }
  (*file)[i] = 0;
  while (str != NULL && str[i] != 0 && str[i] == ' ')
    i++;
  *argv = &str[i];
  return (0);
}

t_token	*my_get_token(t_token *t, int id, int nb)
{
  int	count;

  count = 0;
  while (t != NULL && t->id > 1 && count < nb)
    {
      t->id == id ? count++ : 0;
      t = t->next;
    }
  return (t);
}

int	r_pipe(t_token *t, char **env, int nb, t_utils *ut)
{
  void	*save;
  pid_t	pid;
  int	fds[2];
  int	status;

  save = t;
  if (nb != 0 && (t = my_get_token(t, 2, nb)) == NULL)
    return (1);
  nb != 0 ? pipe(fds) : 0;
  status = 0;
  if ((pid = (nb != 0 ? fork() : 1)) == 0)
    {
      close(fds[0]);
      dup2(fds[1], 1);
      my_exit_1(r_pipe(save, env, nb - 1, ut), save, env, ut);
    }
  else if (pid > 0)
    {
      nb != 0 ? close(fds[1]) : 0;
      nb != 0 ? dup2(fds[0], 0) : 0;
      nb != 0 && check_prev_sep(save, nb - 1) != 3
	? waitpid(pid, &status, WNOWAIT) : waitpid(pid, &status, 0);
      return (my_redir(t, env, ut) + WEXITSTATUS(status));
    }
  return (-1);
}

int	my_init_rec(t_token *t, char **env, int nb, t_utils *ut)
{
  pid_t	pid;
  int	status;

  status = 0;
  if (nb == 0)
    return (my_redir(t, env, ut));
  if ((pid = fork()) == 0)
    my_exit_1(r_pipe(t, env, nb, ut) * -1, t, env, ut);
  else if (pid > 0)
    {
      waitpid(pid, &status, 0);
      return (WEXITSTATUS(status));
    }
  return (-1);
}

int	my_pipes(t_token *t, char **env, t_utils *ut)
{
  int	nb;
  int	ret;
  void	*save;

  nb = 0;
  save = t;
  ret = 0;
  while (t != NULL && t->id > 1)
    {
      t->id == 2 ? nb++ : 0;
      t = t->next;
    }
  ret = my_init_rec(save, env, nb, ut);
  return (ret);
}
