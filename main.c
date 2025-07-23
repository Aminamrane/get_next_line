#include <stdio.h>
#include "utils.h"
#include <stdlib.h>


int main(void) {
    char *test1 = "Bonjour\nSalut";
    char *test2 = "Sans retour";
    char *test3 = "\nDirect";
    char *test4 = "End\n";

    char *result;

    result = clean_leftover(test1);
    printf("Test 1: \"%s\"\n", result);
    free(result);

    result = clean_leftover(test2);
    printf("Test 2: \"%s\"\n", result ? result : "(null)");
    free(result);

    result = clean_leftover(test3);
    printf("Test 3: \"%s\"\n", result);
    free(result);

    result = clean_leftover(test4);
    printf("Test 4: \"%s\"\n", result);
    free(result);

    return 0;
}