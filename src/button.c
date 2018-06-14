/*
** button.c for tekpaint in /home/morgan/rendu/gfx_tekpaint
**
** Made by Morgan Simon
** Login   <morgan@epitech.net>
**
** Started on  Thu Jan  7 23:08:49 2016 Morgan Simon
** Last update Tue Jan 26 16:27:20 2016 mathieu
*/

#include <lapin.h>
#include "my.h"

void    reset_sqaure_button(t_prog *prog)
{
  int                   i;
  t_bunny_position      pos[2];
  t_color               color;

  color.full = GREY;
  i = 1;
  while (i < (WIDTH / 100))
    {
      pos[0].x = LINE_INTER * i;
      pos[0].y = 0;
      pos[1].x = pos[0].x;
      pos[1].y = COL_INTER;
      tekline(prog->array, pos, &color);
      i++;
    }
  pos[0].x = LINE_INTER * i;
  pos[1].x = pos[0].x;
  tekline(prog->array, pos, &color);
}

void    sqaure_button(t_prog *prog)
{
  t_bunny_position      pos1[2];
  t_bunny_position      pos2[2];
  t_color               color;

  color.full = WHITE;
  pos1[0].x = LINE_INTER * prog->button_h;
  pos1[0].y = 0;
  pos1[1].x = pos1[0].x;
  pos1[1].y = COL_INTER;
  pos2[0].x = pos1[0].x + LINE_INTER;
  pos2[0].y = 0;
  pos2[1].x = pos2[0].x;
  pos2[1].y = COL_INTER;
  reset_sqaure_button(prog);
  tekline(prog->array, pos1, &color);
  tekline(prog->array, pos2, &color);
  return;
}

void    set_button_horizontal(t_prog *prog)
{
  int	i;

  i = 0;
  if (prog->mouse.x < LINE_INTER &&
      prog->mouse.y < COL_INTER && prog->brush == 1)
    {
      prog->button_h = 0;
      reset_sqaure_button(prog);
    }
  while (i != H_BUTTON)
    {
      if (prog->mouse.x > (LINE_INTER * i)
	  && prog->mouse.x < ((LINE_INTER * i) + LINE_INTER)
	  && prog->mouse.y < COL_INTER && prog->brush == 1)
	{
	  prog->button_h = i;
	  if (prog->button_h > 0)
	    sqaure_button(prog);
	  return;
	}
      i++;
    }
  if (prog->button_h > 0)
    sqaure_button(prog);
  return;
}

void	set_button_vertical(t_prog *prog)
{
  if (prog->mouse.x > 10 && prog->mouse.x < 89 && prog->mouse.y > 500
      &&  prog->mouse.y < 729 && prog->brush == 1)
    pipette_brush(prog);
  else if (prog->mouse.x > 10 && prog->mouse.x < 90 && prog->mouse.y > 740
	   &&  prog->mouse.y < 755 && prog->brush == 1)
    pipette_brush(prog);
  else
    prog->button_v = 0;
  return;
}

void    set_button(t_prog *prog)
{
  set_button_horizontal(prog);
  set_button_vertical(prog);
}
