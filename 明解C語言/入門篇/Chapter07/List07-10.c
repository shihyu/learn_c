/*
以0.01為單位，從0.0反覆遞增到1.0
*/

#include  <stdio.h>

int main(void) {
    int    i;
    float  x;

    for (i = 0; i <= 100; i++) {
        x = i / 100.0;
        printf("x = %f\n", x);
    }

    return (0);
}
