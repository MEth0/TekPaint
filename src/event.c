/*
** event.c for tekpaint.c in /home/morgan/rendu/gfx_tekpaint
**
** Made by Morgan Simon
** Login   <morgan@epitech.net>
**
** Started on  Thu Jan  7 23:06:58 2016 Morgan Simon
** Last update Tue Jan 26 22:44:50 2016 mathieu
*/

#include <lapin.h>
#include "my.h"

void    set_brush_color_abs(t_prog *prog)
{
  if (prog->keyboard[BKS_R])
    prog->color_brush->full  = RED;
  if (prog->keyboard[BKS_G])
    prog->color_brush->full = GREEN;
  if (prog->keyboard[BKS_B])
    prog->color_brush->full = BLUE;
  if (prog->keyboard[BKS_W])
    prog->color_brush->full = WHITE;
  if (prog->keyboard[BKS_A])
    prog->color_brush->full = BLACK;
}

void    set_brush_color(t_prog *prog)
{
  if (prog->keyboard[BKS_R] && prog->color_brush->argb[RED_CMP] < 252)
    prog->color_brush->argb[RED_CMP] += 3;
  if (prog->keyboard[BKS_G] && prog->color_brush->argb[GREEN_CMP] < 252)
    prog->color_brush->argb[GREEN_CMP] += 3;
  if (prog->keyboard[BKS_B] && prog->color_brush->argb[BLUE_CMP] < 252)
    prog->color_brush->argb[BLUE_CMP] += 3;
  if (prog->keyboard[BKS_W])
    {
      if (prog->color_brush->argb[RED_CMP] < 252)
	prog->color_brush->argb[RED_CMP] += 3;
      if (prog->color_brush->argb[GREEN_CMP] < 252)
	prog->color_brush->argb[GREEN_CMP] += 3;
      if (prog->color_brush->argb[BLUE_CMP] < 252)
	prog->color_brush->argb[BLUE_CMP] += 3;
    }
  if (prog->keyboard[BKS_A])
    {
      if (prog->color_brush->argb[RED_CMP] > 2)
	prog->color_brush->argb[RED_CMP] -= 3;
      if (prog->color_brush->argb[GREEN_CMP] > 2)
	prog->color_brush->argb[GREEN_CMP] -= 3;
      if (prog->color_brush->argb[BLUE_CMP] > 2)
	prog->color_brush->argb[BLUE_CMP] -= 3;
    }
}

void			color_hint(t_prog *prog)
{
  t_bunny_position	pos;

  pos.x = 10;
  pos.y = 200;
  while (pos.y <= 280)
    {
      pos.x = 10;
      while (pos.x <= 90)
	{
	  tekpixel(prog->array, &pos, prog->color_brush);
	  pos.x++;
	}
      pos.y++;
    }
  squares(prog);
  squares2(prog);
  squares3(prog);
}

void    set_brush(t_prog *prog)
{
  if (prog->keyboard[BKS_UP])
    prog->brush_size++;
  if (prog->keyboard[BKS_DOWN] && prog->brush_size > 1)
    prog->brush_size--;
  if (prog->keyboard[BKS_LSHIFT])
    set_brush_color_abs(prog);
  if (prog->keyboard[BKS_I])
    rev_array(prog);
  else
    set_brush_color(prog);
  color_hint(prog);
}
