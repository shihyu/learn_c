/*
輸出型態及變數的大小
*/

#include  <stdio.h>

int main(void) {
    int     na, nb;
    double  dx, dy;

    printf("sizeof(int)     = %u\n", (unsigned)sizeof(int));
    printf("sizeof(double)  = %u\n", (unsigned)sizeof(double));

    printf("sizeof(na)      = %u\n", (unsigned)sizeof(na));
    printf("sizeof(dx)      = %u\n", (unsigned)sizeof(dx));

    printf("sizeof(na + nb) = %u\n", (unsigned)sizeof(na + nb));
    printf("sizeof(na + dy) = %u\n", (unsigned)sizeof(na + dy));
    printf("sizeof(dx + dy) = %u\n", (unsigned)sizeof(dx + dy));

    return (0);
}
