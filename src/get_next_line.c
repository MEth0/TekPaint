/*
** get_next_line.c for gnl in /home/morgan/rendu/CPE_2015_getnextline
**
** Made by Morgan Simon
** Login   <morgan@epitech.net>
**
** Started on  Mon Jan  4 10:44:03 2016 Morgan Simon
** Last update Wed Jan 27 10:17:54 2016 Morgan SIMON
*/

#include <unistd.h>
#include <stdlib.h>
#include "lapin.h"
#include "get_next_line.h"

char    *my_strncpy(char *dest, char *src, int n)
{
  int   a;

  a = 0;
  while (a < n && src[a] != '\0')
    {
      dest[a] = src[a];
      a++;
    }
  if (n < a)
    {
      dest[a] = '\0';
    }
  return (dest);
}

char		*new_line(char *str, int i, char *buf, int *start)
{
  char		*new_line;
  int		len;

  len = 0;
  if (str != NULL)
    {
      while (str[len])
	len++;
    }
  if ((new_line = bunny_malloc((len + i + 1) * sizeof(char *))) == NULL)
    return (NULL);
  my_strncpy(new_line, str, len);
  my_strncpy(new_line + len, buf + *start, i);
  new_line[len + i] = '\0';
  bunny_free(str);
  *start += i + 1;
  return (new_line);
}

char		*get_next_line(const int fd)
{
  static char	buf[READ_SIZE + 1];
  static int	start;
  static int	ret;
  char		*str;
  int		i;

  i = 0;
  str = NULL;
  while (1)
    {
      if (start >= ret)
	{
	  start = 0;
	  if ((ret = read(fd, buf, READ_SIZE)) == 0)
	    return (str);
	  if (ret == -1)
	    return (NULL);
	  i = 0;
	}
      if (buf[start + i] == '\n')
	return (str = new_line(str, i, buf, &start));
      if (start + i == ret - 1)
	str = new_line(str, i + 1, buf, &start);
      i++;
    }
}
