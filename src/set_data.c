/*
** set_data.c for set_data in /home/desria_m/rendu/rendu_infographie/gfx_wolf3d
**
** Made by mathieu desriac
** Login   <desria_m@epitech.net>
**
** Started on  Wed Dec 16 16:06:49 2015 mathieu desriac
** Last update Tue Jan 26 23:38:47 2016 Morgan
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <lapin.h>
#include "my.h"

int	set_data(t_prog *prog, char **av)
{
  int		i;
  t_color	color;

  i = 0;
  prog->off_set.x = 100;
  prog->off_set.y = 100;
  color.full = WHITE;
  prog->brush_size = 3;
  prog->array = load_bitmap("res/gui.bmp", prog);
  prog->array_save = load_bitmap("res/pic.bmp", prog);
  prog->bmp_save = prog->bmp_tmp;
  if (av[1])
    load_ini(prog->array, av[1]);
  if ((prog->color_brush = bunny_malloc(sizeof(t_color *))) == NULL)
    return (-1);
  color.full = BLACK;
  prog->color_brush[0] = color;
  while (av[i] != NULL)
      i++;
  return (i);
}
