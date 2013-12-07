/***************************
    檔名:ch3_07.c
    功能:遞增/遞減運算子
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int i = 5, j = 10, a, b;
    int x = 5, y = 10, c, d;
    a = 1 + i++;
    b = 1 + j--;
    c =  1 + ++x;
    d =  1 + --y;
    printf("i = %d\n", i);
    printf("j = %d\n", j);
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("c = %d\n", c);
    printf("d = %d\n", d);
    system("pause");
}
