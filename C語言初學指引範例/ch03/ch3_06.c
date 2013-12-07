/***************************
    檔名:ch3_06.c
    功能:位元邏輯運算子
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    unsigned short int x = 100, y = 50, p = 3, xx;
    xx = ~x;
    printf("p=3\n");
    printf("x=01100100\n");
    printf("y=00110010\n");
    printf("--------------------\n");
    printf("not x    ==> %d\n", xx);
    printf("x and y  ==> %d\n", (x & y));
    printf("x or y   ==> %d\n", (x | y));
    printf("x xor y  ==> %d\n", (x ^ y));
    printf("x >> p   ==> %d\n", (x >> p));
    printf("x << p   ==> %d\n", (x << p));
    system("pause");
}
