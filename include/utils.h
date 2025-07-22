#ifndef UTILS_H
# define UTILS_H

size_t str_len(const char *s);
int find_newline(const char *s);
char *str_join(char *s1, const char *s2);
void free_buffer(char **buf);