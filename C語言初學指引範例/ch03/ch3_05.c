/***************************
    檔名:ch3_05.c
    功能:邏輯運算子
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int x = 1, y = 0; /*  x為真,y為假  */
    printf("1代表真,0代表假\n");
    printf(" x=%d", x);
    printf(" y=%d\n", y);
    printf("--------------------\n");
    printf("not x    ==> %d\n", !x);
    printf("x and y  ==> %d\n", (x && y));
    printf("x or y   ==> %d\n", (x || y));
    printf("x xor y  ==> %d\n", ((x && !y) || (!x && y)));
    printf("x nand y ==> %d\n", !(x && y));
    printf("x nor y  ==> %d\n", !(x || y));
    system("pause");
}
