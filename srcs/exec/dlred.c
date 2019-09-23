#include <42sh.h>

char		*find_var_env_val(char **env, char *str)
{
  char		*new;
  char		*save;
  int		i;
  int		j;

  i = -1;
  while (env != NULL && env[++i] != NULL)
    {
      j = 0;
      while (env[i][j] == str[j] && env[i][j] != 0)
	j++;
      if (env[i][j] == '=' && env[i][j + 1] != 0)
	{
	  save = &env[i][j + 1];
	  if ((new = malloc(sizeof(char) * (my_strlen(save)+ 1)))
	      == NULL)
	    return (NULL);
	  j = -1;
	  while (save[++j] != 0)
	    new[j] = save[j];
	  new[j] = 0;
	  return (new);
	}
    }
  return (NULL);
}

int		replaces_env_var(char **argv, char **env)
{
  int		i;

  i = 0;
  while (argv != NULL && argv[i] != NULL)
    {
      if (my_strlen(argv[i]) > 1 && argv[i][0] == '$')
	argv[i] = find_var_env_val(env, &(argv[i][1]));
      i++;
    }
  return (0);
}

int		my_left_rd_son(int fds[2], char *file)
{
  char          *str;

  close(fds[0]);
  write(2, ">", 1);
  str = get_next_line(0);
  while (match(str, file) != 1)
    {
      write(fds[1], str, my_strlen(str));
      write(fds[1], "\n", 1);
      write(2, ">", 1);
      str = get_next_line(0);
    }
  return (0);
}

int		my_left_rd_father(t_redi *redi, char **env, t_utils *ut)
{
  pid_t		pid;
  int		status;
  int		fds[2];

  pipe(fds);
  status = 0;
  if ((pid = fork()) == 0)
    {
      my_left_rd_son(fds, redi->file);
      my_exit_2(0, redi, env, ut);
    }
  else if (pid > 0)
    {
      close(fds[1]);
      dup2(fds[0], 0);
      waitpid(pid, &status, 0);
      return (execute(redi->argv, env, ut));
    }
  return (1);
}

int		my_left_rd(t_redi *redi, char **env, t_utils *ut)
{
  pid_t		pid;
  int		status;

  status = 0;
  if ((pid = fork()) == 0)
    my_exit_2(-1 * my_left_rd_father(redi, env, ut), redi, env, ut);
  else if (pid > 0)
    {
      waitpid(pid, &status, 0);
      return (WEXITSTATUS(status));
    }
  return (1);
}
