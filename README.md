# Get Next Line

This is the README file for the "get_next_line" project.

## Description

The "get_next_line" function is a function that reads a file line by line. It is a useful function to have when working with files that have a large amount of data or when you need to process data line by line.

## Usage

To use the "get_next_line" function, you need to include the appropriate header file and call the function with the file descriptor and a pointer to a string where the line will be stored. The function will return 1 if a line was read successfully, 0 if the end of the file was reached, or -1 if an error occurred.

Here is an example of how to use the "get_next_line" function:

```c
#include "get_next_line.h"

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line = NULL;
    int ret;

    while ((ret = get_next_line(fd, &line)) > 0) {
        printf("%s\n", line);
        free(line);
    }

    if (ret == 0) {
        printf("End of file reached\n");
    } else {
        printf("An error occurred\n");
    }

    close(fd);
    return 0;
}
```
