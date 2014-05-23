/*
輸出物件的位址
*/

#include  <stdio.h>

int main(void) {
    int nx;
    double  dx;
    int vc[3];

    printf("nx   的位址：%p\n", &nx);
    printf("dx   的位址：%p\n", &dx);
    printf("vc[0]的位址：%p\n", &vc[0]);
    printf("vc[1]的位址：%p\n", &vc[1]);
    printf("vc[2]的位址：%p\n", &vc[2]);

    return (0);
}
