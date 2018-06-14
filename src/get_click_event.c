/*
** get_click_event.c for get_click_event in /home/desria-m/rendu/rendu_infographie/gfx_tekpaint
**
** Made by mathieu
** Login   <desria-m@epitech.net>
**
** Started on  Tue Jan 26 16:41:29 2016 mathieu
** Last update Wed Jan 27 10:44:54 2016 Morgan SIMON
*/

#include <unistd.h>
#include "get_next_line.h"
#include "my.h"

void	next_event(t_prog *prog)
{
  char  *buff;

  write(1, "enter file name :\n", 18);
  buff = get_next_line(0);
  if (prog->array_load != NULL)
    {
      bunny_delete_clipable(&prog->array_load->clipable);
      prog->array_load = NULL;
    }
  prog->array_load = load_bitmap(buff, prog);
  if (prog->array_load != NULL)
    {
      write(1, "Loading...\n", 11);
      cp_array_r(prog->array, prog->array_load, prog->off_set);
      write(1, "Loading...\n", 11);
    }
  prog->button_h = 0;
}

void	get_click_event(t_prog *prog)
{
  char	*buff;

  if (prog->button_h == 10)
    {
      write(1, "enter file name :\n", 18);
      buff = get_next_line(0);
      save(prog->array, buff);
    }
  else if (prog->button_h == 9)
    {
      write(1, "enter file name :\n", 18);
      buff = get_next_line(0);
      write(1, "Saving...\n", 10);
      cp_array(prog->array, prog->array_save, prog->off_set);
      bmp_save(prog->array_save, prog, buff);
      write(1, "Saved !\n", 8);
    }
  else if (prog->button_h == 8)
    {
      next_event(prog);
    }
  else if (prog->button_h == 7)
    exit (0);
}
