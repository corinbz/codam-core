/*
https://medium.com/@lannur-s/gnl-c3cff1ee552b

• Repeated calls (e.g., using a loop) to your get_next_line() function should
let you read the text file pointed to by the file descriptor, one line at a
time.
• Your function should return the line that was read. If there is nothing
else to read or if an error occurred, it should return NULL.
• Make sure that
your function works as expected both when reading a file and when reading from
the standard input.
• Please note that the returned line should include the
terminating \n character, except if the end of file was reached and does not end
with a \n character.

*/

#include "get_next_line.h"
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

char *ft_strjoin(char const *s1, char const *s2) {
  size_t index;
  char *result;

  index = 0;
  result = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char)) + 1);
  if (result == NULL)
    return (NULL);
  while (*s1) {
    result[index] = *s1;
    index++;
    s1++;
  }
  while (*s2) {
    result[index] = *s2;
    index++;
    s2++;
  }
  result[index] = '\0';
  return (result);
}

char *ft_strdup(const char *str) {
  size_t str_len;
  int i;
  char *result;
  char *s;

  s = (char *)str;
  str_len = ft_strlen((char *)str);
  i = 0;
  result = malloc((str_len + 1) * sizeof(char));
  if (result == NULL)
    return (NULL);
  while (str[i]) {
    result[i] = s[i];
    i++;
  }
  result[i] = '\0';
  return (result);
}
char *ft_substr(char const *s, unsigned int start, size_t len) {
  size_t index;
  size_t substr_len;
  char *result;

  if (!s)
    return (NULL);
  if ((unsigned int)ft_strlen(s) < start)
    return (ft_strdup(""));
  substr_len = ft_strlen(s + start);
  if (substr_len < len)
    len = substr_len;
  result = (char *)malloc((len + 1) * sizeof(char));
  if (!result)
    return (NULL);
  index = 0;
  while (index < len) {
    result[index] = s[start + index];
    index++;
  }
  result[index] = '\0';
  return (result);
}

void read_and_join(int fd, char **curr_line) {
  int bytes_read;
  char *buffer;
  buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
  bytes_read = read(fd, buffer, BUFFER_SIZE);
  if (bytes_read <= 0)
    return;
  buffer[bytes_read] = '\0';
  *curr_line = ft_strjoin(*curr_line, buffer);
  free(buffer);
}

int found_new_line(char *str) {
  if (!str)
    return (0);
  while (*str) {
    if (*str == '\n')
      return (1);
    str++;
  }
  return (0);
}

// char *get_next_line(int fd) {
//   static char *curr_line = NULL;
//   size_t nl_position = 0;
//   char *temp;
//   size_t i = 0;
//   if (fd < 0 || BUFFER_SIZE <= 0)
//     return (NULL);
//   if (curr_line == NULL)
//     curr_line = ft_strjoin("", "");
//   while (!found_new_line(curr_line)) {
//     read_and_join(fd, &curr_line);
//     if (ft_strlen(curr_line) == 0) {
//       free(curr_line);
//       return NULL;
//     }
//   }
//   while (curr_line[nl_position] != '\n')
//     nl_position++;
//   temp = (char *)malloc((nl_position + 2) * sizeof(char));
//   if (!temp)
//     return (NULL);
//   while (i <= nl_position) {
//     temp[i] = curr_line[i];
//     i++;
//   }
//   temp[nl_position + 1] = '\0';
//   curr_line =
//       ft_substr(curr_line, nl_position + 1, ft_strlen(curr_line) -
//       nl_position);
//   return (temp);
// }
char *get_next_line(int fd) {
  static char *curr_line = NULL;
  size_t nl_position;
  size_t i;

  if (fd <= 0 || BUFFER_SIZE <= 0)
    return NULL;
  if (curr_line == NULL)
    curr_line = ft_strjoin("", "");
  read_and_join(fd, &curr_line);
  return (curr_line);
}
int main(int argc, char *argv[]) {
  int fd = open("text.txt", O_RDONLY);
  char *line;
  while ((line = get_next_line(fd)) != NULL) {
    printf("%s", line);
    free(line);
  }
  close(fd);
  return EXIT_SUCCESS;
}
