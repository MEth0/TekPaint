/*
** my.c for my in /home/simon-z/rendu/Info/gfx_tekpaint
** 
** Made by Morgan
** Login   <simon-z@epitech.net>
** 
** Started on  Mon Jan 25 19:51:32 2016 Morgan
** Last update Mon Jan 25 20:52:01 2016 Morgan
*/

#include <lapin.h>
#include "my.h"

const char      *my_itoa(unsigned int i, char *b)
{
  const char    *digit;
  char          *p;
  unsigned int  shifter;

  digit = "0123456789";
  p = b;
  shifter = i;
  while (shifter > 0)
    {
      p++;
      shifter = shifter / 10;
    }
  while (i > 0)
    {
      *--p = digit[i % 10];
      i = i / 10;
    }
  return (b);
}
