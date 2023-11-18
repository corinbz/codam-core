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

char *get_before_nl(char *s);
char *get_after_nl(char *s);

//reads the text file untill it finds newline or EOF
void read_line(int fd, char **text, char **tmp);

//parses the text and returns the string before newline
//text now contains the extra chars after newline
char *parse_line(char **text, char **tmp);

char *get_next_line(int fd);
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
