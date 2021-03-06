/*
** tekline_sqrt.c for tekline_sqrt in /home/desria-m/rendu/rendu_infographie/gfx_tekpaint
**
** Made by mathieu
** Login   <desria-m@epitech.net>
**
** Started on  Tue Jan 26 20:57:20 2016 mathieu
** Last update Tue Jan 26 21:08:31 2016 mathieu
*/

#include "lapin.h"
#include "my.h"

int     set_my_line_sqrt(t_bunny_pixelarray *pix,
			t_bunny_position *pos,
			t_my_line *line_p)

{
  t_my_line     line;

  line.pix = pix;
  line.pos = pos;
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

int     vertline_sqrt(t_my_line line, t_prog *prog)
{
  while (line.pos_pix.y != (line.pos[1]).y)
    {
      sqaure_brush(prog, &line.pos_pix);
      line.pos_pix.y = ((line.pos[1]).y > (line.pos[0]).y) ?
	(line.pos_pix.y + 1) : (line.pos_pix.y - 1);
    }
  sqaure_brush(prog, &line.pos_pix);
  return (0);
}

void    tekline_sqrt(t_bunny_pixelarray *pix,
		    t_bunny_position *pos,
		    t_prog *prog)
{
  t_my_line     line;

  if (set_my_line_sqrt(pix, pos, &line) == 1)
    {
      vertline_sqrt(line, prog);
      return;
    }
  while (line.pos_pix.x != (pos[1]).x)
    {
      sqaure_brush(prog, &line.pos_pix);
      line.pos_pix.x = ((pos[1]).x > (pos[0]).x) ?
	(line.pos_pix.x + 1) : (line.pos_pix.x - 1);
      line.e = line.e + line.delta_e;
      while (line.e >= 0.5)
	{
	  sqaure_brush(prog, &line.pos_pix);
	  line.pos_pix.y = ((pos[1]).y > (pos[0]).y) ?
	    (line.pos_pix.y + 1) : (line.pos_pix.y - 1);
	  line.e -= 1;
	}
      sqaure_brush(prog, &line.pos_pix);
    }
}
