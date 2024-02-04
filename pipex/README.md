##Some documentation


1. open
2. close
3. read
4. write
5. malloc
6. free
7. perror
`perror` is a function in C and C++ programming languages that is used to print a descriptive error message to the standard error stream (`stderr`). It's typically used in conjunction with system calls and library functions. When these calls or functions fail, they often set a global variable called `errno` to a code representing the error that occurred. The `perror` function can then be used to display a human-readable string that describes this error.

The `perror` function takes one argument, which is a string. This string is printed first, followed by a colon and a space, and then the error message corresponding to the current value of `errno`. If the argument is a null pointer or points to an empty string, `perror` just prints the error message.

Here's an example of how you might use `perror` in a C program:

```c
#include <stdio.h>
#include <errno.h>

int main() {
    FILE *file = fopen("non_existent_file.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }
    // Rest of the program...
    return 0;
}
```

In this example, if the `fopen` function fails to open the file (perhaps because it doesn't exist), it sets `errno` to an error code. The `perror` function is then called to print a message to `stderr` that includes the string "Error opening file" and a description of the error.
8. strerror
9. access
10. dup
11. dup2
12. execve
13. exit
14. fork
15. pipe
16. unlink
17. wait
18. waitpid