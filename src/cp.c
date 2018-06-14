/*
** cp.c for cp in /home/desria-m/rendu/rendu_infographie/gfx_tekpaint
**
** Made by mathieu
** Login   <desria-m@epitech.net>
**
** Started on  Mon Jan 25 14:43:58 2016 mathieu
** Last update Tue Jan 26 23:28:49 2016 Morgan
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include <stdlib.h>
#include <lapin.h>
#include "my.h"

int		cp_line(t_bunny_position	pos_src,
			t_bunny_position	pos_dest,
			t_bunny_pixelarray	*array_src,
			t_bunny_pixelarray	*array_dest)
{
  t_color	color;
  unsigned int	pix;

  while (pos_dest.x != array_dest->clipable.clip_width)
    {
      pix = pos_src.y*(array_src->clipable.buffer.width) + pos_src.x;
      color.full = get_pixel(array_src, pix);
      tekpixel(array_dest, &pos_dest, &color);
      pos_dest.x += 1;
      pos_src.x+= 1;
    }
  return (0);
}

int			cp_array(t_bunny_pixelarray	*array_src,
				 t_bunny_pixelarray	*array_dest,
				 t_bunny_position	off_set)
{
  t_bunny_position	pos_src;
  t_bunny_position	pos_dest;

  pos_src = off_set;
  pos_dest.x = 0;
  pos_dest.y = 0;
  if ((array_src->clipable.clip_width * array_src->clipable.clip_height) <
      (array_dest->clipable.clip_width * array_dest->clipable.clip_height))
      return (1);
  while (pos_dest.y != array_dest->clipable.clip_height)
    {
      cp_line(pos_src, pos_dest, array_src, array_dest);
      pos_dest.y += 1;
      pos_src.y += 1;
    }
  return (0);
}

int     cp_line_r(t_bunny_position pos_src,
		  t_bunny_position pos_dest,
		  t_bunny_pixelarray *array_src,
		  t_bunny_pixelarray *array_dest)
{
  t_color color;
  unsigned int	pix;

  while (pos_dest.x != array_dest->clipable.clip_width)
    {
      pix = pos_src.y*(array_src->clipable.buffer.width) + pos_src.x;
      color.full = get_pixel(array_src, pix);
      tekpixel(array_dest, &pos_dest, &color);
      pos_dest.x += 1;
      pos_src.x+= 1;
    }
  return (0);
}

int     cp_array_r(t_bunny_pixelarray *array_src,
		   t_bunny_pixelarray *array_dest,
		   t_bunny_position off_set)
{
  t_bunny_position pos_src;
  t_bunny_position pos_dest;

  pos_dest = off_set;
  pos_src.x = 0;
  pos_src.y = 0;
  while (pos_dest.y != array_dest->clipable.clip_height)
    {
      cp_line(pos_src, pos_dest, array_dest, array_src);
      pos_dest.y += 1;
      pos_src.y += 1;
    }
  return (0);
}
