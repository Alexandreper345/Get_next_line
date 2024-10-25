//#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd;
    char str[265];

    fd = open("testo.txt",O_RDWR);

    while(read(fd,str,2) > 0)
    {
        printf("%s",str);
    }
    close(fd);
    return 0;

}