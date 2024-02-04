## Some documentation

1. open
2. close
3. read
4. write
5. malloc
6. free
### 7. Perror
<details>
<summary>read more</summary>
Is a function in C and C++ programming languages that is used to print a descriptive error message to the standard error stream (`stderr`). It's typically used in conjunction with system calls and library functions. When these calls or functions fail, they often set a global variable called `errno` to a code representing the error that occurred. The `perror` function can then be used to display a human-readable string that describes this error.

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
</details> 

### 8. strerror
<details>
<summary>read more</summary>
`strerror` is a function in the C and C++ programming languages that is used to interpret an error number, typically the `errno` value, into a human-readable string that describes the error. It's often used in conjunction with system calls and library functions that set the `errno` variable when they encounter errors.

The `strerror` function takes one argument, which is an integer representing an error number, and it returns a pointer to a string that describes the error. The string that `strerror` returns is static, meaning it's stored in a fixed location and doesn't need to be freed by the programmer.

Here's an example of how you might use `strerror` in a C program:

```c
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main() {
    FILE *file = fopen("non_existent_file.txt", "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }
    // Rest of the program...
    return 0;
}
```
In this example, if the `fopen` function fails to open the file (perhaps because it doesn't exist), it sets `errno` to an error code. The `strerror` function is then called to convert this error code into a string, which is printed to the standard output along with the message "Error opening file".
</details> 

### 9. access
<details>
<summary>read more</summary>
The `access` function is a system call in Unix-like operating systems (including Linux) and is also available in the C and C++ standard libraries. It is used to check the accessibility of a file or directory based on the real user ID rather than the effective user ID. 

The function takes two arguments: the path to the file or directory, and an integer representing the type of access you want to check for. The access modes you can check for are represented by the following constants:

- `F_OK`: Tests for the existence of the file.
- `R_OK`: Tests for read permission.
- `W_OK`: Tests for write permission.
- `X_OK`: Tests for execute (or search for directories) permission.

The function returns 0 if the requested access is granted, and -1 otherwise. If the function returns -1, you can check `errno` to see what caused the error.

Here's an example of how you might use `access` in a C program:

```c
#include <unistd.h>
#include <stdio.h>

int main() {
    if (access("myfile.txt", F_OK) != -1) {
        printf("File exists.\n");
    } else {
        printf("File does not exist.\n");
    }
    return 0;
}
```

In this example, the `access` function is used to check if the file `myfile.txt` exists. If the file exists, the program prints "File exists.", otherwise it prints "File does not exist.".
</details> 

### 10. dup
<details>
<summary>read more</summary>
The `dup` function is a system call used in Unix-like operating systems, including Linux, and is also available in the C and C++ standard libraries. It is used to create a new file descriptor that is a duplicate of an existing file descriptor.

The `dup` function takes one argument, which is the file descriptor that you want to duplicate. It returns a new file descriptor that refers to the same open file, pipe, or device as the original file descriptor. The new file descriptor is the lowest-numbered file descriptor that is not currently open.

Here's an example of how you might use `dup` in a C program:

```c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int filedesc = open("myfile.txt", O_RDONLY);
    int dupdesc = dup(filedesc);

    printf("Original descriptor: %d\n", filedesc);
    printf("Duplicate descriptor: %d\n", dupdesc);

    close(filedesc);
    close(dupdesc);

    return 0;
}
```

In this example, the `open` function is used to open a file and get a file descriptor. The `dup` function is then used to create a duplicate of this file descriptor. The original and duplicate file descriptors are then printed to the standard output. Finally, both file descriptors are closed with the `close` function.
</details> 

### 11. dup2
<details>
<summary>read more</summary>
The `dup2` function is a system call used in Unix-like operating systems, including Linux, and is also available in the C and C++ standard libraries. It is used to create a new file descriptor that is a duplicate of an existing file descriptor, similar to the `dup` function. However, unlike `dup`, `dup2` allows you to specify the value of the new file descriptor.

The `dup2` function takes two arguments: the old file descriptor and the new file descriptor. If the new file descriptor is already open, it is first closed before being reused. If the old and new file descriptors are identical, `dup2` does nothing and just returns the new file descriptor.

Here's an example of how you might use `dup2` in a C program:

```c
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    int filedesc = open("myfile.txt", O_RDONLY);
    int newdesc = 5;

    if (dup2(filedesc, newdesc) == -1) {
        printf("Failed to duplicate file descriptor.\n");
    } else {
        printf("Duplicated file descriptor %d as %d\n", filedesc, newdesc);
    }

    close(filedesc);
    close(newdesc);

    return 0;
}
```

In this example, the `open` function is used to open a file and get a file descriptor. The `dup2` function is then used to create a duplicate of this file descriptor with a specified new descriptor value. If the duplication is successful, the original and duplicate file descriptors are printed to the standard output. Finally, both file descriptors are closed with the `close` function.

</details> 

### 12. execve
<details>
<summary>read more</summary>
1. `execve`: The `execve` function is a system call used in Unix-like operating systems, including Linux, and is also available in the C and C++ standard libraries. It is used to execute a new program in the context of the current process.

   The `execve` function takes three arguments: the path to the program to be executed, an array of strings representing the arguments to be passed to the new program, and an array of strings representing the environment for the new program. The function replaces the current process image with a new process image, effectively replacing the currently running program with a new one.

   Here's an example of how you might use `execve` in a C program:

   ```c
   #include <unistd.h>

   int main() {
       char *args[] = {"/bin/ls", "-l", NULL};
       char *env[] = {NULL};

       execve(args[0], args, env);

       return 0;
   }
   ```

   In this example, the `execve` function is used to execute the `ls` command with the `-l` option. The current process is replaced with the `ls` command.
</details> 

### 13. exit
<details>
<summary>read more</summary>
exit: The exit function is a standard library function in C and C++ that is used to terminate the execution of a program. It takes one argument, which is the exit status of the program.

The exit function performs cleanup tasks such as flushing buffers and closing files before terminating the program. The exit status is returned to the operating system and can be retrieved by another process (such as the parent process).

Here's an example of how you might use exit in a C program:
```c
#include <stdlib.h>

int main() {
    // Some code...

    if (some_error_condition) {
        exit(1);
    }

    // More code...

    exit(0);
}
```

In this example, the exit function is used to terminate the program if an error condition is true. If the program runs without encountering the error condition, it terminates with an exit status of 0, indicating successful execution.

</details> 

### 14. fork
<details>
<summary>read more</summary>
fork: The fork function is a system call used in Unix-like operating systems, including Linux, and is also available in the C and C++ standard libraries. It is used to create a new process by duplicating the existing process. The new process is called the child process, and the process that calls fork is the parent process. Both processes continue execution from the point where fork was called. The fork function returns 0 in the child process and the child's process ID in the parent process.

```c
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // This block will be executed by the child process
    } else if (pid > 0) {
        // This block will be executed by the parent process
    } else {
        // Fork failed
    }

    return 0;
}
```

</details> 

### 15. pipe
<details>
<summary>read more</summary>
The pipe function is a system call used in Unix-like operating systems to create a pipe, which is a unidirectional data channel that can be used for interprocess communication. The pipe function takes one argument, an array of two integers, and returns two file descriptors: the first for reading from the pipe, and the second for writing to the pipe.

```c
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);
    // fd[0] is for reading, fd[1] is for writing
    return 0;
}
```

</details> 

### 16. unlink
<details>
<summary>read more</summary>
The unlink function is a system call used in Unix-like operating systems to remove a file. When a file is unlinked, it is not actually removed from the disk; instead, its link count is decremented. When the link count reaches zero, the file is actually deleted.

```c
#include <unistd.h>

int main() {
    unlink("/path/to/file");
    return 0;
}
```
</details> 

### 17. wait
<details>
<summary>read more</summary>
The wait function is a system call used in Unix-like operating systems for a process to pause until one of its child processes terminates. The wait function also retrieves the child's exit status.

```c
</details> 
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
    } else if (pid > 0) {
        int status;
        wait(&status);
        // The child process has terminated
    }

    return 0;
}
```
</details> 

### 18. waitpid
<details>
<summary>read more</summary>
The waitpid function is similar to wait, but it waits for a specific child process to terminate.

```c
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
    } else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        // The specific child process has terminated
    }

    return 0;
}
```
</details> 
