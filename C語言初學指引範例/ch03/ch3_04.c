/***************************
    檔名:ch3_04.c
    功能:比較運算子
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int x = 10, y = 20;
    printf(" x=%d", x);
    printf(" y=%d\n", y);
    printf("1代表真,0代表假\n");
    printf("x==y ==> %d\n", (x == y));
    printf("x!=y ==> %d\n", (x != y));
    printf("x>y  ==> %d\n", (x > y));
    printf("x<y  ==> %d\n", (x < y));
    printf("x>=y ==> %d\n", (x >= y));
    printf("x<=y ==> %d\n", (x <= y));
    system("pause");
}
