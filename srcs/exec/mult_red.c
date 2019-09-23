#include <42sh.h>

int		multi_use_father(int fds[2], int fd)
{
  char		*str;

  close(fds[1]);
  while ((str = get_next_line(fds[0])) != 0)
    {
      write(fd, str, my_strlen(str));
      write(fd, "\n", 1);
      free(str);
    }
  close(fds[0]);
  return (0);
}

int		usefull_mul_red(t_redi *red, char **env, t_utils *ut)
{
  pid_t		pid;
  int		status;
  int		fds[2];
  int		mod;
  int		fd;

  status = 0;
  pipe(fds);
  if ((pid = fork()) == 0)
    {
      close(fds[0]);
      dup2(fds[1], 1);
      my_exit_2((red->id == 3 ? my_left_rd(red, env, ut) :
		      my_left_r(red, env, ut)), red, env, ut);
    }
  else if (pid > 0)
    {
      mod = red->next->id == 6 ? (O_CREAT | O_RDWR | O_TRUNC) :
	(O_CREAT | O_RDWR);
      waitpid(pid, &status, 0);
      fd = open(red->next->file, mod, 0644);
      multi_use_father(fds, fd);
      return (WEXITSTATUS(status));
    }
  return (1);
}

int		useless_mul_red(t_redi *red, char **env, t_utils *ut)
{
  pid_t		pid;
  int		status;
  int		fd;

  status = 0;
  if ((pid = fork()) == 0)
    my_exit_2((red->id == 5 ? my_right_rd(red, env, ut) :
		    my_right_r(red, env, ut)), red, env, ut);
  else if (pid > 0)
    {
      waitpid(pid, &status, 0);
      fd = open(red->next->file, O_RDONLY, 0644);
      if (fd == -1 &&
	  fprintf(stderr, "[Error]Can't open %s.\n", red->next->file) >= 0)
	return (-1);
      dup2(fd, 0);
      close(fd);
      return (WEXITSTATUS(status));
    }
  return (1);
}

int		mult_redi(t_redi *red, char **env, t_utils *ut)
{
  pid_t		pid;
  int		status;

  status = 0;
  if (red->id == 3 || red->id == 4)
    return (usefull_mul_red(red, env, ut));
  else
    {
      if ((pid = fork()) == 0)
	my_exit_2(useless_mul_red(red, env, ut), red, env, ut);
      else if (pid > 0)
	{
	  waitpid(pid, &status, 0);
	  return (WEXITSTATUS(status));
	}
      return (1);
    }
}

void		my_free_3(t_redi *redi)
{
  void		*save;

  while (redi != NULL)
    {
      save = redi;
      if (redi->type == 1 && redi->file != NULL)
	free(redi->file);
      redi = redi->next;
      free(save);
    }
}
