# include "my_readline.h"

t_data		*init_data(t_data *data)
{
  if ((data->str = malloc(sizeof(char) * 2048)) == NULL ||
       (data->save = malloc(sizeof(char) * 2048)) == NULL)
    {
      printf(RED"Error"RES": malloc failed.\n");
      return (NULL);
    }
  if ((data->term = malloc(sizeof(*data->term))) == NULL)
    {
      printf(RED"Error"RES": malloc failed.\n");
      return (NULL);
    }
  if ((data->term->term = malloc(sizeof(char) * 2048)) == NULL)
    {
      printf(RED"Error"RES": malloc failed.\n");
      return (NULL);
    }
  if ((data->term->buff = malloc(sizeof(char) * 2048)) == NULL)
    {
      printf(RED"Error"RES": malloc failed.\n");
      return (NULL);
    }
  data->limit[0] = 0;
  data->limit[1] = 0;
  return (data);
}
