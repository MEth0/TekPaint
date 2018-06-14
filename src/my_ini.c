/*
** my_ini.c for ini in /home/simon-z/rendu/Info/gfx_tekpaint/src
** 
** Made by Morgan
** Login   <simon-z@epitech.net>
** 
** Started on  Wed Jan 20 13:39:55 2016 Morgan
** Last update Tue Jan 26 23:36:01 2016 Morgan
*/

#include <unistd.h>
#include <lapin.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

void    my_putchar_fd(char c, int fd)
{
  write(fd, &c, 1);
}

void    my_put_nbr_fd(unsigned int nb, int fd)
{
  if (nb > 9)
    my_put_nbr_fd(nb / 10, fd);
  my_putchar_fd((nb % 10) + '0', fd);
}

int	parse_ini(const char *check, int width, int height)
{
  if (!check || !width || !height)
    {
      write(1, "Wrong file.\n", 12);
      return (1);
    }
  return (0);
}

int     load_ini(t_bunny_pixelarray *array, char *av)
{
  t_bunny_ini   *ini;
  int           i;
  const char    *check;
  int           width;
  int           height;

  i = 0;
  if ((ini = bunny_load_ini(av)) == NULL)
    {
      write(1, "Wrong file.\n", 12);
      return (1);
    }
  check = bunny_ini_get_field(ini, "pic", "color", 0);
  width = my_getnbr(bunny_ini_get_field(ini, "pic", "width", 0));
  height = my_getnbr(bunny_ini_get_field(ini, "pic", "height", 0));
  if ((parse_ini(check, width, height)) == 1)
    return (1);
  while (i < (width * height))
    {
      ((unsigned int *)array->pixels)[i] =
	my_getnbr(bunny_ini_get_field(ini, "pic", "color", i));
      i++;
    }
  return (0);
}

int             save(t_bunny_pixelarray *pix, char *av)
{
  unsigned long pixels;
  unsigned long i;
  int           fd;
  char		str[11];

  i = 0;
  pixels = WIDTH * HEIGHT;
  if ((fd = open(av, O_RDWR | O_CREAT, 0664)) <= 0)
    return (1);
  write(fd, "[pic]\n", 6);
  write(fd, "width=", 6);
  my_put_nbr_fd((pix->clipable).clip_width, fd);
  write(fd, "\nheight=", 8);
  my_put_nbr_fd((pix->clipable).clip_height, fd);
  write(fd, "\ncolor=", 7);
  write(1, "Saving...\n", 10);
  while (i <= pixels)
    {
      write(fd, my_itoa(get_pixel(pix, i), str), 10);
      write(fd, ",", 1);
      i++;
    }
  write(1, "Saved !\n", 8);
  return (0);
}
