/*
** rev_array.c for rev_array in /home/desria-m/rendu/rendu_infographie/gfx_tekpaint
**
** Made by mathieu
** Login   <desria-m@epitech.net>
**
** Started on  Tue Jan 26 21:26:23 2016 mathieu
** Last update Wed Feb 17 18:53:34 2016 Morgan SIMON
*/

#include <unistd.h>
#include "my.h"

int	rev_array(t_prog *prog)
{
  int	i;

  i = 0;
  prog->array_save = bunny_new_pixelarray(1024, 868);
  cp_array(prog->array, prog->array_save, prog->off_set);
  while (i != prog->array_save->clipable.buffer.width
	 * prog->array_save->clipable.buffer.height)
    {
      ((unsigned int *)prog->array_save->pixels)[i] = 0xFFFFFF -
	(((unsigned int *)prog->array_save->pixels)[i]);
      i++;
    }
  cp_array_r(prog->array, prog->array_save, prog->off_set);
  bunny_delete_clipable(&prog->array_save->clipable);
  return (0);
}
