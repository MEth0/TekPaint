/*
** brush2.c for brush in /home/simon-z/rendu/Info/gfx_tekpaint/src
** 
** Made by Morgan
** Login   <simon-z@epitech.net>
** 
** Started on  Mon Jan 25 14:15:45 2016 Morgan
** Last update Tue Jan 26 18:41:41 2016 Morgan
*/

#include <stdio.h>
#include <lapin.h>
#include "my.h"

void			circle_loop(t_bunny_position	*pos,
				    t_bunny_position	pos_l,
				    t_bunny_position    *posw,
				    t_prog		*prog)
{
  pos_l.x = pos->x + posw->x;
  pos_l.y = pos->y + posw->y;
  tekpixel_paint(prog->array, &pos_l, prog->color_brush);
  pos_l.x = pos->x + posw->y;
  pos_l.y = pos->y + posw->x;
  tekpixel_paint(prog->array, &pos_l, prog->color_brush);
  pos_l.x = pos->x - posw->x;
  pos_l.y = pos->y + posw->y;
  tekpixel_paint(prog->array, &pos_l, prog->color_brush);
  pos_l.x = pos->x - posw->y;
  pos_l.y = pos->y + posw->x;
  tekpixel_paint(prog->array, &pos_l, prog->color_brush);
  pos_l.x = pos->x - posw->x;
  pos_l.y = pos->y - posw->y;
  tekpixel_paint(prog->array, &pos_l, prog->color_brush);
  pos_l.x = pos->x - posw->y;
  pos_l.y = pos->y - posw->x;
  tekpixel_paint(prog->array, &pos_l, prog->color_brush);
  pos_l.x = pos->x + posw->x;
  pos_l.y = pos->y - posw->y;
  tekpixel_paint(prog->array, &pos_l, prog->color_brush);
  pos_l.x = pos->x + posw->y;
  pos_l.y = pos->y - posw->x;
  tekpixel_paint(prog->array, &pos_l, prog->color_brush);
  posw->y++;
}

void                    circle(t_prog			*prog,
			       t_bunny_position		*pos,
			       int			i)
{
  t_bunny_position      pos_l;
  t_bunny_position      posw;
  int			over;

  posw.y = 0;
  posw.x = (prog->brush_size - i);
  over = 1 - posw.x;
  pos_l.x = 0;
  pos_l.y = 0;
  while (posw.y <= posw.x)
    {
      circle_loop(pos, pos_l, &posw, prog);
      if (over <= 0)
	over += 2 * posw.y + 1;
      else
	{
	  posw.x--;
	  over += 2 * (posw.y - posw.x) + 1;
	}
    }
  if (i != prog->brush_size)
    {
      i += 1;
      circle(prog, pos, i);
    }
}

void			line(t_prog			*prog,
			     t_bunny_position		*pos)
{
  t_bunny_position	old_pos[2];

  old_pos[0].x = pos->x + (prog->brush_size / 2);
  old_pos[0].y = pos->y - (prog->brush_size / 2);
  old_pos[1].x = pos->x - prog->brush_size;
  old_pos[1].y = pos->y + prog->brush_size;
  tekline_paint(prog->array, old_pos, prog->color_brush);
}
