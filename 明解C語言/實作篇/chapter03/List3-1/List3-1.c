/*
    顯示物件的位址
*/

#include  <stdio.h>

int main(void) {
    int   x;
    int   y;
    long  z;

    printf("x的位址=%p\n", &x);
    printf("y的位址=%p\n", &y);
    printf("z的位址=%p\n", &z);

    system("PAUSE");
    return (0);
}
