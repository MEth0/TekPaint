/*
** bmp.c for bmp in /home/morgan/rendu/gfx_tekpaint/morgan
**
** Made by Morgan Simon
** Login   <morgan@epitech.net>
**
** Started on  Thu Jan  7 20:24:27 2016 Morgan Simon
** Last update Tue Jan 26 22:45:05 2016 mathieu
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <lapin.h>
#include "bmp.h"
#include "my.h"

t_bunny_pixelarray      *get_info(int fd, t_prog *prog)
{
  char                  buffer[4096];
  t_head                head;
  t_info                info;
  int                   r;

  r = read(fd, &head, sizeof(head));
  if (r != sizeof(head))
    return (NULL);
  r = read(fd, &info, sizeof(info));
  if (r != sizeof(info))
    return (NULL);
  r = head.offbits - (sizeof(head) + sizeof(info));
  if (r > 0)
    read(fd, buffer, r);
  prog->bmp_tmp.head = head;
  prog->bmp_tmp.info = info;
  return (bunny_new_pixelarray(info.width, info.height));
}

void    reverse_color(t_color *color)
{
  t_color buffer;

  buffer = *color;
  (color->argb)[0] = buffer.argb[3];
  (color->argb)[1] = buffer.argb[2];
  (color->argb)[2] = buffer.argb[1];
  (color->argb)[3] = buffer.argb[0];
}

int	init_file(t_bunny_pixelarray **pix,
		  t_bunny_position *pos,
		  int *fd,
		  t_prog *prog)
{
  if ((*pix = get_info(*fd, prog)) == NULL)
    return (1);
  pos->x = 0;
  pos->y = ((*pix)->clipable).clip_height - 1;
  return (0);
}

t_bunny_pixelarray      *load_bitmap(const char *file, t_prog *prog)
{
  t_color               buf;
  int                   ret;
  int                   fd;
  t_bunny_position      pos;
  t_bunny_pixelarray    *pix;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  if (init_file(&pix, &pos, &fd, prog))
    return (NULL);
  ret = 1;
  while (ret > 0)
    {
      ret = read(fd, buf.argb, 4);
      if (ret == 4)
	{
	  reverse_color(&buf);
	  tekpixel(pix, &pos, &buf);
	}
      pos.x += 1;
      pos.y = (pos.x >= (pix->clipable).clip_width ? pos.y - 1 : pos.y);
      pos.x = (pos.x >= (pix->clipable).clip_width ? 0 : pos.x);
    }
  close(fd);
  return (pix);
}
