#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "utils.h"

char *get_next_line(int fd)
{
    static char *leftover = NULL;
    char buffer[BUFFER_SIZE + 1];
    char *str = NULL;
    int bytes_read = 1;

    if (leftover != NULL)
        str = str_join(NULL, leftover);

    while (bytes_read > 0 && find_newline(str) == -1) {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        buffer[bytes_read] = '\0';
        str = str_join(str, buffer);
    }

    if (bytes_read == 0 && str_len(str) == 0) {
        free(str);
        return NULL;
    }

    int idx = find_newline(str);

   
    char *line = malloc(idx + 2);
    if (!line) {
        free(str);
        return NULL;
    }
    for (int i = 0; i <= idx; i++)
        line[i] = str[i];
    line[idx + 1] = '\0';

    
    size_t surplus_len = str_len(str) - (idx + 1);
    char *new_leftover = malloc(surplus_len + 1);
    if (!new_leftover) {
        free(str);
        free(line);
        return NULL;
    }
    for (size_t i = 0; i < surplus_len; i++)
        new_leftover[i] = str[idx + 1 + i];
    new_leftover[surplus_len] = '\0';

    
    if (leftover) {
        free(leftover);
    }
    leftover = new_leftover;

    free(str);
    return line;
}
