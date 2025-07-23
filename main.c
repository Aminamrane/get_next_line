#include <stdio.h>
#include "utils.h"
#include <stdlib.h>


int main(void) {
    char *test1 = "Bonjour\nComment ça va ?";
    char *test2 = "Ligne sans retour";
    char *test3 = "Juste\n";
    char *test4 = "\nCommence par newline";

    char *line;

    line = extract_line(test1);
    printf("Test 1: \"%s\"\n", line);
    free(line);

    line = extract_line(test2);
    printf("Test 2: \"%s\"\n", line);
    free(line);

    line = extract_line(test3);
    printf("Test 3: \"%s\"\n", line);
    free(line);

    line = extract_line(test4);
    printf("Test 4: \"%s\"\n", line);
    free(line);

    return 0;
}