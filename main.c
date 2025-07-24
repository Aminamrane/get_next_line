#include <stdio.h>
#include "utils.h"
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char **argv)
{

    int fd = open(argv[1], O_RDONLY);
    char *line;

    if (argc != 2)
    {
        write(2, "User: ./gnl <file.txt>\n", 24);
        return 1;
    }

    if (fd == -1)
    {
        write(2, "Erreur d'ouverture\n", 19);
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        size_t i = 0;
        while (line[i])
            i++;
        write(1, line, i); 
        free(line);
    }

    close(fd);
    return 0;
}