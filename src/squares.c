/*
** squares.c for squares in /home/simon-z/rendu/Info/gfx_tekpaint
** 
** Made by Morgan
** Login   <simon-z@epitech.net>
** 
** Started on  Tue Jan 26 22:25:26 2016 Morgan
** Last update Tue Jan 26 22:38:58 2016 Morgan
*/

#include <lapin.h>
#include "my.h"

void                    squares(t_prog *prog)
{
  t_bunny_position      pos;
  t_color               color;

  pos.x = 10;
  pos.y = 300;
  color.full = BLACK;
  color.argb[RED_CMP] = prog->color_brush->argb[RED_CMP];
  while (pos.y <= 340)
    {
      pos.x = 10;
      while (pos.x <= 30)
	{
	  tekpixel(prog->array, &pos, &color);
	  pos.x++;
	}
      pos.y++;
    }
}

void                    squares2(t_prog *prog)
{
  t_bunny_position      pos;
  t_color               color;

  pos.x = 40;
  pos.y = 300;
  color.full = BLACK;
  color.argb[GREEN_CMP] = prog->color_brush->argb[GREEN_CMP];
  while (pos.y <= 340)
    {
      pos.x = 40;
      while (pos.x <= 60)
	{
	  tekpixel(prog->array, &pos, &color);
	  pos.x++;
	}
      pos.y++;
    }
}

void                    squares3(t_prog *prog)
{
  t_bunny_position      pos;
  t_color               color;

  pos.x = 70;
  pos.y = 300;
  color.full = BLACK;
  color.argb[BLUE_CMP] = prog->color_brush->argb[BLUE_CMP];
  while (pos.y <= 340)
    {
      pos.x = 70;
      while (pos.x <= 90)
	{
	  tekpixel(prog->array, &pos, &color);
	  pos.x++;
	}
      pos.y++;
    }
}
