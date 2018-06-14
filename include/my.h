/*
** my.h for tekpaint in /home/morgan/rendu/gfx_tekpaint
**
** Made by Morgan Simon
** Login   <morgan@epitech.net>
**
** Started on  Tue Jan  5 14:32:02 2016 Morgan Simon
** Last update Tue Jan 26 23:32:24 2016 Morgan
*/

#ifndef MY_H_
# define MY_H_

#include "bmp.h"

# define WIDTH (1124)
# define HEIGHT (868)
# define FPS (30)
# define GREY (0x848484)
# define LINE_FIRST (100)
# define LINE_INTER (100)
# define COL_INTER (100)
# define H_BUTTON (11)

typedef struct          s_prog
{
  t_bunny_window        *win;
  t_bunny_pixelarray    *array;
  t_bunny_position	off_set;
  t_bunny_pixelarray    *array_save;
  t_bunny_pixelarray    *array_load;
  t_bmp                 bmp_tmp;
  t_bmp			bmp_save;
  t_bunny_position      mouse;
  t_bunny_position	old_mose[2];
  t_color               *color_brush;
  bool                  brush;
  unsigned char         brush_size;
  char                  button_h;
  char			button_v;
  const bool            *keyboard;
}                       t_prog;

typedef struct		s_my_line
{
  t_bunny_pixelarray    *pix;
  t_bunny_position      *pos;
  t_color               *color;
  float                 e;
  float                 delta_x;
  float                 delta_y;
  float                 delta_e;
  t_bunny_position      pos_pix;
}			t_my_line;

/*
** my_getnbr.c
*/

int			my_strlen(const char			*str);
unsigned int		my_getnbr(const char			*str);

/*
** tekpixel.c
*/

void			tekpixel(t_bunny_pixelarray		*pix,
				 t_bunny_position		*pos,
				 t_color			*color);
unsigned int		get_pixel(t_bunny_pixelarray		*pix,
				  unsigned int			cnt);
void			tekpixel_paint(t_bunny_pixelarray	*pix,
				       t_bunny_position		*pos,
				       t_color			*color);

/*
** brush.c
*/

void			paint_brush(t_prog			*prog,
				    t_bunny_position		*pos);
void                    sqaure_brush(t_prog			*prog,
				     t_bunny_position		*pos);
void			pipette_brush(t_prog			*prog);
void			set_brush_type(t_prog			*prog);

/*
** brush2.c
*/

void                    circle(t_prog				*prog,
			       t_bunny_position			*pos,
			       int				i);
void			fill(t_bunny_position			*pos,
			     t_prog				*prog);
void                    line(t_prog				*prog,
			     t_bunny_position			*pos);

/*
** set_data.c
*/

int			set_data(t_prog				*prog,
				 char				**av);

/*
** tekline_paint.c
*/

void			tekline_paint(t_bunny_pixelarray	*pix,
				      t_bunny_position		*pos,
				      t_color			*color);

/*
** bmp.c
*/

t_bunny_pixelarray      *load_bitmap(const char			*file,
				     t_prog			*prog);
void			reverse_color(t_color			*color);

/*
** event.c
*/

void			set_brush(t_prog			*prog);

/*
** button.c
*/

void			set_button(t_prog			*prog);

/*
** tekline.c
*/

void			tekline(t_bunny_pixelarray		*pix,
				t_bunny_position		*pos,
				t_color				*color);

/*
** my_ini.c
*/

int			save(t_bunny_pixelarray			*pix,
			     char				*av);
int			load_ini(t_bunny_pixelarray		*array,
				 char				*av);

/*
** my.c
*/

const char		*my_itoa(unsigned int			i,
				 char				*b);

/*
** get_pixel_pos.c
*/

t_color			get_pixel_pos(t_bunny_pixelarray	*pix,
				      t_bunny_position		*pos);

/*
** cp.c
*/

int			cp_array(t_bunny_pixelarray		*array_src,
				 t_bunny_pixelarray		*array_dest,
				 t_bunny_position		off_set);

int			cp_array_r(t_bunny_pixelarray		*array_src,
				   t_bunny_pixelarray		*array_dest,
				   t_bunny_position		off_set);

/*
** bmp_save.c
*/

int			bmp_save(t_bunny_pixelarray		*array,
				 t_prog				*prog,
				 const char			*path);

/*
** get_click_event.c
*/

void			get_click_event(t_prog			*prog);

/*
** tekline_cir.c
*/

void			tekline_cir(t_bunny_pixelarray		*pix,
				    t_bunny_position		*pos,
				    t_prog			*prog);

/*
** tekline_sqrt.c
*/

void			tekline_sqrt(t_bunny_pixelarray		*pix,
				     t_bunny_position		*pos,
				     t_prog			*prog);

/*
** rev_array.c
*/

int			rev_array(t_prog			*porg);

/*
** squares.c
*/

void                    squares(t_prog				*prog);
void                    squares2(t_prog				*prog);
void                    squares3(t_prog				*prog);

#endif /* !MY_H_ */
