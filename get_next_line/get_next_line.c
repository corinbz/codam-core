/*

• Repeated calls (e.g., using a loop) to your get_next_line() function should let
you read the text file pointed to by the file descriptor, one line at a time.
• Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL.
• Make sure that your function works as expected both when reading a file and when
reading from the standard input.
• Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character. 

*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

char *get_next_line(int fd)
{
  char buffer[42];
  ssize_t bytesRead;
  if (fd == -1) {
    return (NULL);
  }
  bytesRead = read(fd, buffer, sizeof(buffer));
  printf("read %zd bytes: %s", bytesRead, buffer);
  return 0; 
}

int main(int argc, char *argv[])
{
  char buffer[1024];
  int fd = open("text.txt", O_RDONLY);
  get_next_line(fd);
  return EXIT_SUCCESS;
}
