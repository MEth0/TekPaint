/*
** my_struc.h for my_struc in /home/desria_m/rendu/rendu_infographie/gfx_tekpaint
** 
** Made by mathieu desriac
** Login   <desria_m@epitech.net>
** 
** Started on  Tue Jan  5 14:50:36 2016 mathieu desriac
** Last update Mon Jan 25 11:41:58 2016 Morgan
*/

#ifndef MY_STRUC_H_
# define MY_STRUC_H_

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

#endif /* !MY_STRUC_H_ */
