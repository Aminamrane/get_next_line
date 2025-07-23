#include <stdio.h>
#include "utils.h"
#include <stdlib.h>


int main(void)
{
    char *s1 = "hello ";
    char *s2 = "world";
    char *result = ft_strjoin(s1, s2);

    printf("Résultat : %s\n", result);

    free(result);

    return 0;
}
