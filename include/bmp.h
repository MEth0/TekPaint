/*
** bmp.h for bmp in /home/morgan/rendu/gfx_tekpaint/morgan
**
** Made by Morgan Simon
** Login   <morgan@epitech.net>
**
** Started on  Thu Jan  7 20:21:37 2016 Morgan Simon
** Last update Tue Jan 26 16:19:27 2016 Morgan
*/

#ifndef BMP_H_
# define BMP_H_

#include <lapin.h>

typedef struct		s_head
{
  unsigned short	type;
  unsigned int		size;
  unsigned short	reserved1;
  unsigned short	reserved2;
  unsigned int		offbits;
} __attribute__((packed)) t_head;

typedef struct		s_info
{
  unsigned int		size;
  signed int		width;
  signed int		height;
  unsigned short	planes;
  unsigned short	bitcount;
  unsigned int		compression;
  unsigned int		sizeimage;
  signed int		xresolution;
  signed int		yresolution;
  unsigned int		clrused;
  unsigned int		clrimportant;
} __attribute__((packed)) t_info;

typedef struct			s_bmp
{
  t_head			head;
  t_info			info;
} __attribute__((packed))	t_bmp;

#endif /* !BMP_H_ */
