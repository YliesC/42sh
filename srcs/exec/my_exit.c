#include <42sh.h>
#include <errno.h>

int	replaces_dol_inte(char **line, int ret)
{
  int	i;

  i = -1;
  ret = ret % 255;
  ret = (ret < 0) ? ret + 255: ret;
  while (line && line[++i])
    if (match(line[i], "$?") == 1)
      {
	free(line[i]);
	if ((line[i] = malloc(sizeof(char) * 4)) == NULL)
	  return (1);
	sprintf(line[i], "%d", ret);
      }
  return (0);
}

int	print_sig(int status)
{
  if (status == SIGHUP)
    printf("Hangup detected on controlling terminal"
	   " or death of controlling process\n");
  else if (status == SIGINT)
    printf("Interrupt from keyboard\n");
  else if (status == SIGQUIT)
    printf("Quit from keyboard\n");
  else if (status == SIGILL)
    printf("Illegal Instruction\n");
  else if (status == SIGABRT)
      printf("Abort signal\n");
  else if (status == SIGFPE)
      printf("Floating point exception\n");
  else if (status == SIGKILL)
      printf("Kill signal\n");
  else if (status == SIGSEGV)
      printf("Invalid memory reference (Segmentation fault)\n");
  else if (status == SIGPIPE)
    printf("Broken pipe: write to pipe with not readers\n");
  else if (status == SIGALRM)
    printf("Timer signal\n");
  else
    my_signals(status);
  return (status > 0 && status < 32 ? status + 128 : WEXITSTATUS(status));
}

int	my_execute2(char **line, t_utils *ut, char **env)
{
  pid_t	s_pid;
  int	status;

  if (access(my_exec_create(line[0], ut->path), X_OK) == -1)
    {
      printf("\033[31m[Error]\033[0m '%s' command not found\n",
	     line[0]);
      return (1);
    }
  if ((s_pid = fork()) == 0)
    {
      setpgid(s_pid, setsid());
      if (execve(my_exec_create(line[0], ut->path), line, env) == -1)
        printf("\033[31m[Error]\033[0m '%s' command not found\n",
               line[0]);
      my_exit_2(1, NULL, env, ut);
    }
  else if (s_pid > 0)
    {
      waitpid(s_pid, &status, 0);
      return (print_sig(status));
    }
  return (1);
}

int	my_exit_2(int re, t_redi *red, char **env, t_utils *ut)
{
  int	i;

  red != NULL ? my_free_3(red) : 0;
  i = -1;
  while (env != NULL && env[++i] != NULL)
    free(env[i]);
  env != NULL ? free(env) : 0;
  ut != NULL ? my_free(ut) : 0;
  exit(re);
  return (0);
}

int	my_exit_1(int re, t_token *t, char **env, t_utils *ut)
{
  env != NULL && t != NULL ? my_free_2(env, t) : 0;
  env != NULL ? free(env) : 0;
  ut != NULL ? my_free(ut) : 0;
  exit(re);
  return (0);
}
