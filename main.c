#include <stdio.h>
#include "utils.h"
#include <stdlib.h>


int main(void)
{
    char *s = "hello\n my name is Amine or Youcef";
    int i = 0;

    i = find_newline(s);
    printf("resultat = %d\n", i);
    return 0;
}
