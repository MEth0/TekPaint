/*
** main.c for tekpaint in /home/morgan/rendu/gfx_tekpaint
**
** Made by Morgan Simon
** Login   <morgan@epitech.net>
**
** Started on  Tue Jan  5 14:32:36 2016 Morgan Simon
** Last update Mon Feb 15 22:55:23 2016 Morgan SIMON
*/

#include <lapin.h>
#include "my.h"

static t_bunny_response mouse_click(t_bunny_event_state	state,
				    t_bunny_mousebutton key,
				    void		*my_data)
{
  t_prog		*prog;

  (void)state;
  prog = my_data;
  if (key == BMB_LEFT && prog->brush == 0)
    {
      prog->brush = 1;
      set_button(prog);
      get_click_event(prog);
    }
  else
    prog->brush = 0;
  return (GO_ON);
}

static t_bunny_response         mouse(const t_bunny_position	*relative,
				      void			*my_data)
{
  const t_bunny_position        *pos_const;
  t_prog                        *prog;

  (void)relative;
  prog = my_data;
  pos_const = bunny_get_mouse_position();
  prog->mouse.x = pos_const->x;
  prog->mouse.y = pos_const->y;
  prog->old_mose[1] = prog->old_mose[0];
  prog->old_mose[0] = prog->mouse;
  if (prog->brush == 1)
    set_brush_type(prog);
  return (GO_ON);
}

static t_bunny_response	key(t_bunny_event_state state,
                            t_bunny_keysym      key,
                            void                *data)
{
  (void)state;
  (void)data;
  if (key == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

static t_bunny_response mainloop(void *my_data)
{
  t_prog		*prog;
  t_bunny_position      pos_array;

  prog = my_data;
  pos_array.x = 0;
  pos_array.y = 0;
  prog->keyboard = bunny_get_keyboard();
  set_brush(prog);
  bunny_blit(&prog->win->buffer, &prog->array->clipable, &pos_array);
  bunny_display(prog->win);
  return (GO_ON);
}

int			main(int ac, char **av)
{
  static t_prog		prog;

  (void)av;
  (void)ac;
  if (set_data(&prog, av) == -1)
    return (-1);
  if ((prog.win = bunny_start(WIDTH, HEIGHT, false, "Tekpaint")) == NULL)
    return (EXIT_FAILURE);
  bunny_set_key_response(key);
  bunny_set_click_response(mouse_click);
  bunny_set_move_response(mouse);
  bunny_set_loop_main_function(mainloop);
  bunny_loop(prog.win, FPS, &prog);
  bunny_free(prog.color_brush);
  bunny_delete_clipable(&prog.array->clipable);
  bunny_stop(prog.win);
  return (EXIT_SUCCESS);
}
