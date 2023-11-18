#include "get_next_line.h"

size_t ft_strlen(const char *str) {
  int len;

  len = 0;
  while (str[len]) 
    len++;
  return (len);
}
