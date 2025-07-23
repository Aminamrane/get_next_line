#include <stdio.h>
#include "utils.h"
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(2, "Usage: ./gnl <fichier>\n", 24);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Erreur d'ouverture");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Ligne : %s", line);
        free(line);
    }

    close(fd);
    return 0;
}