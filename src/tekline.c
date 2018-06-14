/*
** tekline.c for tekline in /home/desria_m/rendu/rendu_infographie/gfx_tekpaint
**
** Made by mathieu desriac
** Login   <desria_m@epitech.net>
**
** Started on  Tue Jan  5 14:47:34 2016 mathieu desriac
** Last update Tue Jan 26 16:21:47 2016 mathieu
*/

#include "lapin.h"
#include "my.h"

int     set_my_line(t_bunny_pixelarray *pix,
		    t_bunny_position *pos,
		    t_color *color,
		    t_my_line *line_p)

{
  t_my_line     line;

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

int     vertline(t_my_line line)
{
  t_color       *color_pix;

  color_pix = line.color;
  while (line.pos_pix.y != (line.pos[1]).y)
    {
      tekpixel(line.pix, &line.pos_pix, color_pix);
      line.pos_pix.y = ((line.pos[1]).y > (line.pos[0]).y) ?
	(line.pos_pix.y + 1) : (line.pos_pix.y - 1);
    }
  tekpixel(line.pix, &line.pos_pix, color_pix);
  return (0);
}

void    tekline(t_bunny_pixelarray *pix,
                t_bunny_position *pos,
                t_color *color)
{
  t_my_line     line;
  t_color       color_pix;

  color_pix = *color;
  if (set_my_line(pix, pos, color, &line) == 1)
    {
      vertline(line);
      return;
    }
  while (line.pos_pix.x != (pos[1]).x)
    {
      tekpixel(pix, &line.pos_pix, &color_pix);
      line.pos_pix.x = ((pos[1]).x > (pos[0]).x) ?
	(line.pos_pix.x + 1) : (line.pos_pix.x - 1);
      line.e = line.e + line.delta_e;
      while (line.e >= 0.5)
        {
          tekpixel(pix, &line.pos_pix, &color_pix);
          line.pos_pix.y = ((pos[1]).y > (pos[0]).y) ?
	    (line.pos_pix.y + 1) : (line.pos_pix.y - 1);
          line.e -= 1;
        }
      tekpixel(pix, &line.pos_pix, &color_pix);
    }
}
