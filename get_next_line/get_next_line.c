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

char	*ft_strdup(const char *str)
{
	size_t	str_len;
	int		i;
	char	*result;
	char	*s;

	s = (char *)str;
	str_len = ft_strlen ((char *)str);
	i = 0;
	result = malloc ((str_len + 1) * sizeof (char));
	if (result == NULL)
		return (NULL);
	while (str[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
char *ft_strjoin(char *s1, char *s2) {
  size_t index;
  char *result;
  size_t j;

  j = 0;
  index = 0;
  result = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char)));
  if (result == NULL)
    return (NULL);
  while (s1[index]) {
    result[index] = s1[index];
    index++;
  }
  while (s2[j]) {
    result[index] = s2[j];
    j++;
    index++;
  }
  result[index] = '\0';
  free(s1);
  return (result);
}

char *ft_substr(char *s, unsigned int start, size_t len) {
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
  free(s);
  return (result);
}

char *ft_strchr(const char *s, int c) {
  char char_c;
  char *char_s;
  int i;

  i = 0;
  char_s = (char *)s;
  char_c = c;
  while (char_s[i] != char_c) {
    if (char_s[i] == '\0') {
      return (NULL);
    }
    i++;
  }
  return ((char *)char_s + i);
}

void ft_bzero(void *s, size_t n) {
  while (n > 0) {
    *(char *)(s) = '\0';
    s++;
    n--;
  }
}
void *ft_calloc(size_t num_elements, size_t element_size) {
  size_t total_size;
  void *result;

  total_size = num_elements * element_size;
  result = malloc(total_size);
  if (result != NULL)
    ft_bzero(result, total_size);
  return (result);
}
char *add_chunk_text(char *text, char *chunk_text) {
  char *temp;

  temp = ft_strjoin(text, chunk_text);
  // free(text);
  return (temp);
}

char *read_file(char *text, int fd) {
  char chunk_text[BUFFER_SIZE + 1];
  int bytes_read;
  bytes_read = 1;
  while (bytes_read > 0) {
    bytes_read = read(fd, chunk_text, BUFFER_SIZE);
    if (bytes_read < 0)
      return (free(text), NULL);
    chunk_text[bytes_read] = '\0';
    text = ft_strjoin(text, chunk_text);
    if (ft_strchr(text, '\n'))
      break;
  }
  return (text);
}

char *get_line(char *text) {
  char *clean_line;
  size_t nl_position = 0;
  size_t index = 0;
  while (text[index]) {
    if (text[index] == '\n') {
      ++nl_position;
      break;
    }
    index++;
    ++nl_position;
  }
  clean_line = ft_substr(text, 0, nl_position);
  return clean_line;
}

char *get_remainer_text(char *text) {
  char *remainder;
  size_t nl_position = 0;
  size_t index = 0;
  if(!text)
    return NULL;
  while (text[index]) {
    if (text[index] == '\n') {
      ++nl_position;
      break;
    }
    index++;
    ++nl_position;
  }
  remainder = ft_substr(text, nl_position, (ft_strlen(text) - nl_position));
  return remainder;
}
char *get_next_line(int fd) {
  static char *text = NULL;
  char *line;
  if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
    return (NULL);
  if (!text)
    text = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
  if(!text)
    return(NULL);
  if (!ft_strchr(text, '\n'))
    text = read_file(text, fd);
  if (!text)
    return (free(text), NULL);
  line = get_line(text);
  text = get_remainer_text(text);
  return (line);
}
int main(int argc, char *argv[]) {
  int fd = open("text.txt", O_RDONLY);
  char *line;
  // while ((line = get_next_line(fd)) != NULL) {
  //   printf("%s", line);
  //   free(line);
  // }
  line = get_next_line(fd);
  printf("%s", line);
  free(line);
  close(fd);
  return 0;
}
