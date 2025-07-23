#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


size_t ft_strlen(const char *s) {

    size_t i = 0;

    while (s[i] != '\0') {

        i++;

    }

    return i;

}

char *ft_strjoin(char *s1, char *s2) {

    char *line;
    int len_total = 0;
    int i = 0;
    int j = 0;

    
    if (!s1) {
        s1 = "";
    }

      if (!s2) {
        s2 = "";
    }

    len_total = ft_strlen(s1) + ft_strlen(s2);
    line = malloc(len_total + 1);

    while (s1[i] != '\0') {
        line[i] = s1[i];
        i++;
    }

    while (s2[j] != '\0') {
        line[i+j] = s2[j];
        j++;
    }

    line[i+j] = '\0';

    return line;

}

int find_newline(const char *s){

    int i = 0;

    while (s[i] != '\0') {

        if (s[i] == '\n') {
            return i;
        }
        i++;
    } 

    return -1;

}