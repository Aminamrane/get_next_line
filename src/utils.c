#include "utils.h"
#include <stdlib.h>


size_t str_len(const char *s)
{
    size_t i = 0;
    if (!s)
        return 0;
    while (s[i])
        i++;
    return i;
}


int find_newline(const char *s)
{
    if (!s)
        return -1;
    for (int i = 0; s[i]; i++) {
        if (s[i] == '\n')
            return i;
    }
    return -1;
}


char *str_join(char *s1, char *s2)
{
    size_t len1 = str_len(s1);
    size_t len2 = str_len(s2);
    char *res = malloc(len1 + len2 + 1);
    if (!res) {
        if (s1)
            free(s1);
        return NULL;
    }
    for (size_t i = 0; i < len1; i++)
        res[i] = s1[i];
    for (size_t i = 0; i < len2; i++)
        res[len1 + i] = s2[i];
    res[len1 + len2] = '\0';
    if (s1)
        free(s1);
    return res;
}


void free_buffer(char **buf)
{
    if (buf && *buf) {
        free(*buf);
        *buf = NULL;
    }
}