#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    int fd;
    char *line;

    fd = open("testo.txt", O_RDWR);
    if (fd < 0) // Verifica se o arquivo foi aberto corretamente
    {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    line = get_next_line(fd);
    while (line != NULL) {
    printf("%s", line);
    free(line); // Não esqueça de liberar a memória
}
    close(fd);
    return 0;
}