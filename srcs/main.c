#include <42sh.h>

static char	*g_prompt;

void		my_handler(int sig)
{
  if (sig == SIGINT)
    {
      write(0, "\n", 1);
      write(0, g_prompt, strlen(g_prompt));
    }
}

void		create_prompt(t_utils *utils)
{
  char		*pwd;
  int		len;

  if ((pwd = get_env_var(utils, "PWD")) == NULL)
    pwd = strdup(YELLOW"[42sh] ~ >"DEFAULT);
  g_prompt = strdup(pwd);
  len = strlen(g_prompt);
  if ((g_prompt = realloc(g_prompt, len + 3)) == NULL)
    return ;
  g_prompt[len] = ':';
  g_prompt[len + 1] = ' ';
  g_prompt[len + 2] = 0;
}

int		main(int ac, char **av, char **env)
{
  t_utils	utils;
  char		*path_history;

  ac = (int)ac;
  av = (char **)av;
  path_history = create_path_history();
  init_struct(&utils);
  add_history_to_list(&(utils.history));
  check_env(&utils, env);
  my_read(&utils);
  add_history_to_file(path_history, utils.history);
  my_free(&utils);
  return (utils.my_exit);
}

int		my_read(t_utils *utils)
{
  char		*buffer;

  signal(SIGINT, &my_handler);
  create_prompt(utils);
  while ((buffer = my_readline(g_prompt, utils)))
    {
      if (main_loop(buffer, utils) == 42)
	{
	  free(buffer);
	  return (42);
	}
      create_prompt(utils);
      get_path(utils);
      free(buffer);
    }
  write(1, "\n", 1);
  return (0);
}

void	my_free(t_utils *utils)
{
  free_struct((t_base *)utils->env);
  free_struct((t_base *)utils->history);
  free_struct((t_base *)utils->alias);
  free_tab(utils->path);
}
