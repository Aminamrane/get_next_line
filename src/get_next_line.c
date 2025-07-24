#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

char *get_next_line(int fd)
{
    static char *leftover;
    char *buffer;
    char *str;
    char *line;
    int bytes_read = 0;
    char *tmp;

    buffer = malloc(BUFFER_SIZE + 1);

    if (!buffer)
    return NULL;

    str = ft_strjoin(NULL, leftover);

    while(find_newline(str) == -1 && (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {

        buffer[bytes_read] = '\0';
        tmp = str;
        str = ft_strjoin(str, buffer);
        free(tmp);    
    }

    line = extract_line(str);
    free(leftover);
    leftover = clean_leftover(str);
    free(buffer);
    free(str);


    return line;

}
