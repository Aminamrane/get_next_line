#include <stdio.h>
#include "utils.h"
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>


int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
        return 1;

    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return 1;

    while ((line = get_next_line(fd)) != NULL)
    {
        size_t i = 0;
        while (line[i])
            i++;
        write(1, line, i);
        free(line);
    }

    write(1, "\n", 1);

    close(fd);
    return 0;
}