#include "randapi.h"
#include <stdio.h>
int main() {
    int   i;
    init_rand();
    printf("get_rand():\n");

    for (i = 0; i < 6; i++) {
        printf("%f  ", get_rand());
    }

    printf("\n");
    printf("get_maxrand(6)\n");

    for (i = 0; i < 6; i++) {
        printf("%d  ", get_maxrand(6));
    }

    printf("\n");
    return 0;
}


