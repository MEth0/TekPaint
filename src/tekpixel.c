/*
** tekpixel.c for tekpixel in /home/morgan/rendu/gfx_tekpaint
**
** Made by Morgan Simon
** Login   <morgan@epitech.net>
**
** Started on  Tue Jan  5 14:34:17 2016 Morgan Simon
** Last update Mon Jan 25 14:17:39 2016 Morgan
*/

#include <lapin.h>
#include "my.h"

int     win(t_bunny_position *pos)
{
  if (pos->x <= 100 || pos->y <= 100 || pos->x > WIDTH)
    return (0);
  return (1);
}

void    tekpixel_paint(t_bunny_pixelarray *pix,
		       t_bunny_position *pos,
		       t_color *color)
{
  int   i;

  i = pos->y * (pix->clipable.buffer.width) + pos->x;
  if (0 <= i && i <= pix->clipable.buffer.width * pix->clipable.buffer.height
      && win(pos) == 1)
    ((unsigned int *)pix->pixels)[i] = color->full;
}

void	tekpixel(t_bunny_pixelarray	*pix,
		 t_bunny_position	*pos,
		 t_color		*color)
{
  int   w;
  int   h;

  w = (pix->clipable).clip_width;
  h = (pix->clipable).clip_height;
  if ((pos->x < w && pos->y < h) && (pos->x >= 0 && pos->y >= 0))
    (((t_color*)pix->pixels)[w * pos->y + pos->x]).full = color->full;
}

unsigned int    get_pixel(t_bunny_pixelarray    *pix,
                          unsigned int          cnt)
{
  unsigned int color;

  color = 0;
  if (cnt <= (unsigned int)pix->clipable.buffer.width *
      pix->clipable.buffer.height)
    color = ((unsigned int *)pix->pixels)[cnt];
  return (color);
}
