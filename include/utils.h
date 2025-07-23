#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

size_t ft_strlen(const char *s);
char *ft_strjoin(char *s1, char *s2);
int find_newline(const char *s);
char *ft_substr(char *s, size_t start, int len);

#endif /* UTILS_H */