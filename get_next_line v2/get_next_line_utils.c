#include "get_next_line.h"

size_t ft_strlen(const char *str) {
  int len;

  len = 0;
  while (str[len]) 
    len++;
  return (len);
}

//calloc
void *ft_calloc(size_t elements, size_t size);
//duplicate the string
char	*ft_strdup(const char *s1);
//join the strings
char	*join_strs(const char *s1, const char *s2);
//check if text contains newline
int	contains_newline(const char *s);
//free the strings
void ft_free_all(char **str1, char **str2, char **str3)
{
  if(str1 && *str1)
  {
    free(*str1);
    *str1 = NULL;
  }
    if(str2 && *str2)
  {
    free(*str2);
    *str2 = NULL;
  }
    if(str2 && *str2)
  {
    free(*str2);
    *str2 = NULL;
  }
}