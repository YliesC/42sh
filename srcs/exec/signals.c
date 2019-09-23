#include <42sh.h>

int	my_signals_other(int status)
{
  if (status == SIGBUS)
    printf("Bus error (bad memory access)\n");
  else if (status == SIGPOLL)
    printf("Pollable event (Sys V).\n");
  else if (status == SIGPROF)
    printf("Profiling timer expired.\n");
  else if (status == SIGSYS)
    printf("Bad argument to routine.\n");
  else if (status == SIGTRAP)
    printf("Trace/breakpoint trap.\n");
  else if (status == SIGURG)
    printf("Urgent condition on socket.\n");
  else if (status == SIGVTALRM)
    printf("Virtual alarm clock.\n");
  else if (status == SIGXCPU)
    printf("CPU time limit exceeded.\n");
  else if (status == SIGXFSZ)
    printf("File size limit exceeded.\n");
  return (0);
}

int	my_signals(int status)
{
  if (status == SIGTERM)
    printf("Termination signal\n");
  else if (status == SIGUSR1)
    printf("User-defined signal 1\n");
  else if (status == SIGUSR2)
    printf("User-defined signal 2\n");
  else if (status == SIGCHLD)
    printf("Child stopped or terminated\n");
  else if (status == SIGCONT)
    printf("Continue if stopped\n");
  else if (status == SIGSTOP)
    printf("Stop process\n");
  else if (status == SIGTSTP)
    printf("Stop typed at tty\n");
  else if (status == SIGTTIN)
    printf("Terminal input for background process\n");
  else if (status == SIGTTOU)
    printf("Terminal output for background process\n");
  return (my_signals_other(status));
}

int	my_check_token(t_token *t)
{
  while (t != NULL)
    {
      if (t->next == NULL && t->id != 7)
	{
	  printf("[Error] Unexepected %s at the end of the command\n", t->str);
	  return (1);
	}
      if (t->next != NULL && t->id > 2 && t->id != 7 && t->next->id != 7)
	{
	  printf("[Error] %s following %s is incorrect command\n",
		 t->next->str, t->str);
	  return (1);
	}
      t = t->next;
    }
  return (0);
}
