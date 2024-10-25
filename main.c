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

    while ((line = get_next_line(fd)) != NULL) // Lê a linha
    {
        printf("%s\n", line); // Imprime a linha lida
        free(line); // Libera a memória alocada pela get_next_line
    }

    close(fd);
    return 0;
}