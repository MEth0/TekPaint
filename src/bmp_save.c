/*
** bmp_save.c for bmp_save in /home/desria-m/rendu/rendu_infographie/gfx_tekpaint
**
** Made by mathieu
** Login   <desria-m@epitech.net>
**
** Started on  Mon Jan 25 19:19:13 2016 mathieu
** Last update Tue Jan 26 23:01:03 2016 mathieu
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <lapin.h>
#include "bmp.h"
#include "my.h"

int	bmp_save(t_bunny_pixelarray *array, t_prog *prog, const char *path)
{
  int			fd;
  unsigned int		pix;
  t_bunny_position	pos;
  t_color		color;

  if ((fd = open(path, O_WRONLY | O_CREAT, 0664)) == -1)
    return (1);
  write(fd, &(prog->bmp_save), sizeof(t_bmp));
  pos.x = 0;
  pos.y = (array->clipable).clip_height - 1;
  while (pos.y != 0)
    {
      pix = pos.y * (array->clipable.buffer.width) + pos.x;
      color.full = get_pixel(array, pix);
      reverse_color(&color);
      write(fd, &color.full, sizeof(unsigned int));
      pos.x += 1;
      pos.y = (pos.x >= (array->clipable).clip_width ? pos.y - 1 : pos.y);
      pos.x = (pos.x >= (array->clipable).clip_width ? 0 : pos.x);
    }
  close(fd);
  return (0);
}
