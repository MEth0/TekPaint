/*
** tekline_paint.c for Tekpaint in /home/morgan/rendu/gfx_tekpaint
**
** Made by Morgan Simon
** Login   <morgan@epitech.net>
**
** Started on  Thu Jan  7 22:43:49 2016 Morgan Simon
** Last update Tue Jan 26 23:25:08 2016 Morgan
*/

#include <lapin.h>
#include "my.h"

int		set_my_line_paint(t_bunny_pixelarray	*pix,
				  t_bunny_position	*pos,
				  t_color		*color,
				  t_my_line		*line_p)
{
  t_my_line	line;

  line.pix = pix;
  line.pos = pos;
  line.color = color;
  line.e = 0;
  line.pos_pix.x = (pos[0]).x;
  line.pos_pix.y = (pos[0]).y;
  line.delta_x = (pos[0]).x - (pos[1]).x;
  line.delta_y = (pos[0]).y - (pos[1]).y;
  *line_p = line;
  if (line.delta_x != 0)
    line.delta_e = ((line.delta_y / line.delta_x) < 0 ) ?
      ((line.delta_y / line.delta_x) * (-1)) : (line.delta_y / line.delta_x);
  else
    return (1);
  *line_p = line;
  return (0);
}

int		vertline_paint(t_my_line line)
{
  t_color       *color_pix;

  color_pix = line.color;
  while (line.pos_pix.y != (line.pos[1]).y)
    {
      tekpixel_paint(line.pix, &line.pos_pix, color_pix);
      line.pos_pix.y = ((line.pos[1]).y > (line.pos[0]).y) ?
	(line.pos_pix.y + 1) : (line.pos_pix.y - 1);
    }
  tekpixel_paint(line.pix, &line.pos_pix, color_pix);
  return (0);
}

void		tekline_paint(t_bunny_pixelarray	*pix,
			      t_bunny_position		*pos,
			      t_color			*color)
{
  t_my_line     line;
  t_color       color_pix;

  color_pix = *color;
  if (set_my_line_paint(pix, pos, color, &line) == 1)
    {
      vertline_paint(line);
      return;
    }
  while (line.pos_pix.x != (pos[1]).x)
    {
      tekpixel_paint(pix, &line.pos_pix, &color_pix);
      line.pos_pix.x = ((pos[1]).x > (pos[0]).x) ?
	(line.pos_pix.x + 1) : (line.pos_pix.x - 1);
      line.e = line.e + line.delta_e;
      while (line.e >= 0.5)
	{
	  tekpixel_paint(pix, &line.pos_pix, &color_pix);
	  line.pos_pix.y = ((pos[1]).y > (pos[0]).y) ?
	    (line.pos_pix.y + 1) : (line.pos_pix.y - 1);
	  line.e -= 1;
	}
      tekpixel_paint(pix, &line.pos_pix, &color_pix);
    }
}
