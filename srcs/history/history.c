#include <42sh.h>

int		add_history_to_file(char *path, t_history *history)
{
  int		fd;
  int		flags;
  mode_t	mode;
  t_history	*tmp;

  mode = S_IRUSR | S_IWUSR;
  flags = O_RDWR | O_CREAT | O_TRUNC;
  if ((fd = open(path, flags, mode)) == -1)
    return (-printf("%s: %m\n", path));
  tmp = history;
  while (tmp && tmp->next != history)
    {
      write(fd, tmp->str, my_strlen(tmp->str));
      write(fd, "\n", 1);
      tmp = tmp->next;
    }
  if (tmp)
    {
      write(fd, tmp->str, my_strlen(tmp->str));
      write(fd, "\n", 1);
    }
  if (close(fd) == -1)
    return (-printf("%s: %m\n", path));
  return (0);
}

int		add_history_to_list(t_history **history)
{
  int		nb;
  int		fd;
  char		*buffer;
  static t_base	*last;

  if ((fd = open(HISTORY_FILE, O_RDWR)) == -1)
    return (-1);
  nb = 1;
  while ((buffer = get_next_line(fd)))
    {
      last = add_to_list((t_base **)history, 1);
      ((t_history *)last)->token = 1;
      ((t_history *)last)->str = b_strdup(buffer);
      ((t_history *)last)->nb = nb++;
      free(buffer);
    }
  if (close(fd))
    return (-1);
  return (0);
}

int	remove_history(t_history **history)
{
  free_history((*history));
  (*history) = NULL;
  return (0);
}

char	*create_path_history()
{
  char	*path_history;
  int	len;

  if ((path_history = getcwd(NULL, 0)) == NULL)
    {
      printf("%m\n");
      return (NULL);
    }
  len = my_strlen(path_history) + my_strlen(HISTORY_FILE) + 2;
  if ((path_history = realloc(path_history, len)) == NULL)
    {
      printf("%m\n");
      return (NULL);
    }
  strcat(path_history, "/");
  strcat(path_history, HISTORY_FILE);
  path_history[len - 1] = 0;
  return (path_history);
}

int	__history(char **args, t_utils *utils)
{
  if (match(args[1], "-c") || match(args[1], "--clear"))
    remove_history(&(utils->history));
  else
    print_liste((t_base *)utils->history);
  return (EXIT_SUCCESS);
}
