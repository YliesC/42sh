/*
** builtin.c for builtin in /home/chahi_y/rendu/PSU_2013_42sh
**
** Made by chahi
** Login   <chahi_y@epitech.net>
**
** Started on  Thu Apr 17 16:41:35 2014 chahi
** Last update Sun May 25 19:32:47 2014 chahi
*/

#include <42sh.h>

int	init_builtin(t_builtin *__tab)
{
  strcpy(__tab[0].str, "cd");
  __tab[0].func = &__cd;
  strcpy(__tab[1].str, "env");
  __tab[1].func = &__env;
  strcpy(__tab[2].str, "setenv");
  __tab[2].func = &__setenv;
  strcpy(__tab[3].str, "unsetenv");
  __tab[3].func = &__unsetenv;
  strcpy(__tab[4].str, "alias");
  __tab[4].func = &__alias;
  strcpy(__tab[5].str, "unalias");
  __tab[5].func = &__unalias;
  strcpy(__tab[6].str, "history");
  __tab[6].func = &__history;
  strcpy(__tab[7].str, "echo");
  __tab[7].func = &__echo;
  strcpy(__tab[8].str, "exit");
  __tab[8].func = &__exit;
  strcpy(__tab[9].str, "cls");
  __tab[9].func = &__clear_screen;
  return (-1);
}

int		builtin(char *bin, char **args, t_utils *utils)
{
  int		i;
  int		exiting;
  t_builtin	__tab[BUILTIN];

  exiting = 1;
  i = init_builtin(__tab);
  while (++i < BUILTIN && exiting != 42)
    if (match(__tab[i].str, bin))
      return (__tab[i].func(args, utils));
  return (-1);
}

int	__exit(char **args, t_utils *utils)
{
  int	number;

  utils = utils;
  number = 0;
  if (args[1])
    number = my_getnbr(args[1]);
  utils->my_exit = number;
  return (42);
}

int	__clear_screen(char **args, t_utils *utils)
{
  args = args;
  utils = utils;
  write(1, "\033c", strlen("\033c"));
  return (EXIT_SUCCESS);
}
