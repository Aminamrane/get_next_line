#include <stdio.h>
#include "utils.h"
#include <stdlib.h>


    int main(void) {

    char *str = "Epitech piscine C";

    
    char *sub1 = ft_substr(str, 2, 1);     
    printf("sub1 = \"%s\"\n", sub1);
    free(sub1);


    char *sub2 = ft_substr(str, 8, 7); 
    printf("sub2 = \"%s\"\n", sub2);
    free(sub2);


    char *sub3 = ft_substr(str, 8, 50);
    printf("sub3 = \"%s\"\n", sub3);
    free(sub3);


    char *sub4 = ft_substr(str, 100, 5);
    printf("sub4 = \"%s\"\n", sub4);
    free(sub4);


    char *sub5 = ft_substr(str, 2, 0);
    printf("sub5 = \"%s\"\n", sub5);
    free(sub5);

    return 0;
}