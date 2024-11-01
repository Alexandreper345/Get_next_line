#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>


int main()
{
    int fd;
    int lines;
    char *line;

    lines = 1;
    fd = open("testo.txt", O_RDWR);
    /*line = get_next_line(fd);
    printf("%s\n", line);
    line = get_next_line(fd);
    printf("%s\n", line);
    line = get_next_line(fd);
    printf("%s\n", line);
    line = get_next_line(fd);
    printf("%s\n", line);*/
   // while ((line = get_next_line(fd)))
    //{
    line = get_next_line(fd);
    printf("%s", line);
    free(line);
    //}
    close(fd);
    return 0;
}