#include <unistd.h>     
#include <fcntl.h>     
#include <stdlib.h>     
#include "get_next_line.h"
#include "utils.h"     

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc != 2) {
        write(2, "Usage: ./gnl <file>\n", 21);
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        write(2, "Error: cannot open file\n", 24);
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL) {
        write(1, line, str_len(line));
        free(line);
    }

    close(fd);
    return (0);
}
