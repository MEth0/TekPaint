/*
** my_getnbr.c for getnbr in /home/simon-z/rendu/Info/gfx_tekpaint
** 
** Made by Morgan
** Login   <simon-z@epitech.net>
** 
** Started on  Mon Jan 25 19:08:46 2016 Morgan
** Last update Mon Jan 25 19:18:16 2016 Morgan
*/

#include <lapin.h>
#include "my.h"

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int		my_compute(int		i, const char		*str,
			   unsigned int	*mul, unsigned int	*res)
{
  unsigned int	add;

  add = 0;
  if (str[i] >= '0' && str[i] <= '9')
    {
      add = *mul * (str[i] - '0');
      *res += add;
      *mul *= 10;
    }
  return (0);
}

unsigned int	my_getnbr(const char *str)
{
  unsigned int	mul;
  int		i;
  unsigned int	res;

  res = 0;
  mul = 1;
  i = my_strlen(str) - 1;
  while (i + 1 > 0)
    {
      my_compute(i, str, &mul, &res);
      i--;
    }
  if (str[0] == '-')
    res = -res;
  return (res);
}
