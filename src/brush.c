/*
** brush.c for brush in /home/morgan/rendu/gfx_tekpaint
**
** Made by Morgan Simon
** Login   <morgan@epitech.net>
**
** Started on  Thu Jan  7 22:40:37 2016 Morgan Simon
** Last update Wed Jan 27 10:44:16 2016 Morgan SIMON
*/

#include <stdio.h>
#include <lapin.h>
#include "my.h"

void    paint_brush(t_prog		*prog,
		    t_bunny_position	*pos)
{
  int   i;
  int   j;

  i = 0;
  pos->y = pos->y - prog->brush_size;
  while (i != prog->brush_size)
    {
      j = 0;
      pos->x = pos->x - prog->brush_size;
      while (j != prog->brush_size)
	{
	  tekpixel_paint(prog->array, pos, prog->color_brush);
	  j++;
	  pos->x = pos->x + j;
	}
      i++;
      pos->y = pos->y + i;
    }
}

void                    sqaure_brush(t_prog		*prog,
				     t_bunny_position	*pos)
{
  t_bunny_position      pos_l[2];

  pos_l[0].x = pos->x - (prog->brush_size / 2);
  pos_l[0].y = pos->y - (prog->brush_size / 2);
  pos_l[1].x = pos_l[0].x + prog->brush_size;
  pos_l[1].y = pos_l[0].y;
  if (pos_l[0].y != pos->y + (prog->brush_size / 2))
    {
      while (pos_l[0].y != pos->y + (prog->brush_size / 2))
	{
	  tekline_paint(prog->array, pos_l, prog->color_brush);
	  pos_l[0].y++;
	  pos_l[1].y++;
	}
    }
  else
    tekpixel_paint(prog->array, pos, prog->color_brush);
}

void                    eraser(t_prog             *prog,
			       t_bunny_position   *pos)
{
  t_bunny_position      pos_l[2];
  t_color		color;

  color.full = WHITE;
  pos_l[0].x = pos->x - (prog->brush_size / 2);
  pos_l[0].y = pos->y - (prog->brush_size / 2);
  pos_l[1].x = pos_l[0].x + prog->brush_size;
  pos_l[1].y = pos_l[0].y;
  if (pos_l[0].y != pos->y + (prog->brush_size / 2))
    {
      while (pos_l[0].y != pos->y + (prog->brush_size / 2))
	{
	  tekline_paint(prog->array, pos_l, &color);
	  pos_l[0].y++;
	  pos_l[1].y++;
	}
    }
  else
    tekpixel_paint(prog->array, pos, prog->color_brush);
}

void		pipette_brush(t_prog *prog)
{
  unsigned int	pix;

  pix = prog->mouse.y * (prog->array->clipable.buffer.width) + prog->mouse.x;
  prog->color_brush->full = get_pixel(prog->array, pix);
}

void		set_brush_type(t_prog *prog)
{
  if (prog->button_h == 1)
    tekline_sqrt(prog->array, prog->old_mose, prog);
  if (prog->button_h == 2)
    paint_brush(prog, &prog->mouse);
  if (prog->button_h == 3)
    eraser(prog, &prog->mouse);
  if (prog->button_h == 4)
    tekline_cir(prog->array, prog->old_mose, prog);
  if (prog->button_h == 5)
    line(prog, &prog->mouse);
  if (prog->button_v == 1)
    pipette_brush(prog);
}
