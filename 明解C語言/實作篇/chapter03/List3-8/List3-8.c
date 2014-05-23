/*
    顯示指向陣列前頭元素的指標
*/

#include  <stdio.h>

int main(void) {
    double  x[5];

    printf("x     = %p\n", x);
    printf("&x[0] = %p\n", &x[0]);

    system("PAUSE");
    return (0);
}
