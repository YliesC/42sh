#include <42sh.h>

int		my_right_r(t_redi *redi, char **env, t_utils *ut)
{
  pid_t		pid;
  int		status;
  int		exec;
  int		fd;

  status = 0;
  pid = fork();
  if (pid == 0)
    {
      if ((fd = open(redi->file, O_RDWR | O_CREAT | O_TRUNC, 0644)) == -1 &&
	  fprintf(stderr, "[Error]Can't create %s\n", redi->file) >= -1)
	my_exit_2(1, redi, env, ut);
      dup2(fd, 1);
      exec = execute(redi->argv, env, ut);
      close(fd);
      my_exit_2(exec, redi, env, ut);
    }
  else if (pid > 0)
    {
      waitpid(pid, &status, 0);
      return (WEXITSTATUS(status));
    }
  return (1);
}

int		my_right_rd(t_redi *redi, char **env, t_utils *ut)
{
  pid_t		pid;
  int		status;
  int		exec;
  int		fd;

  pid = fork();
  status = 0;
  if (pid == 0)
    {
      if ((fd = open(redi->file, O_RDWR | O_CREAT | O_APPEND, 0644)) == -1 &&
	  fprintf(stderr, "[Error]Can't create or write %s\n", redi->file) >= -1)
	my_exit_2(1, redi, env, ut);
      dup2(fd, 1);
      exec = execute(redi->argv, env, ut);
      close(fd);
      my_exit_2(exec, redi, env, ut);
    }
  else if (pid > 0)
    {
      waitpid(pid, &status, 0);
      return (WEXITSTATUS(status));
    }
  return (1);
}

int		my_left_r(t_redi *redi, char **env, t_utils *ut)
{
  pid_t		pid;
  int		status;
  int		exec;
  int		fd;

  pid = fork();
  status = 0;
  if (pid == 0)
    {
      if ((fd = open(redi->file, O_RDONLY)) == -1 &&
	  fprintf(stderr, "[Error]Can't open %s\n", redi->file) >= -1)
	my_exit_2(1, redi, env, ut);
      dup2(fd, 0);
      exec = execute(redi->argv, env, ut);
      close(fd);
      my_exit_2(exec, redi, env, ut);
    }
  else if (pid > 0)
    {
      waitpid(pid, &status, 0);
      return (WEXITSTATUS(status));
    }
  return (1);
}

int		my_handle_red(t_redi *redi, char **env, t_utils *ut)
{
  if (redi != NULL && redi->next != NULL)
    return (mult_redi(redi, env, ut));
  if (redi != NULL && redi->file != NULL && redi->id == 3)
    return (my_left_rd(redi, env, ut) * -1);
  else if (redi != NULL && redi->file != NULL && redi->id == 4)
    return (my_left_r(redi, env, ut));
  else if (redi != NULL && redi->file != NULL && redi->id == 5)
    return (my_right_rd(redi, env, ut));
  else if (redi != NULL && redi->file != NULL && redi->id == 6)
    return (my_right_r(redi, env, ut));
  return (execute(redi->argv, env, ut));
}

int		check_prev_sep(t_token *t, int nb)
{
  if (nb != 0 && t != NULL)
    t = my_get_token(t, 2, nb);
  while (t != NULL && t->id > 2)
    {
      if (t->id != 7)
	return (t->id);
      t = t->next;
    }
  return (2);
}
