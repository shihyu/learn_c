/***************************
    檔名:ch7_30.c
    功能:巨集取代函式
 ***************************/

#include <stdio.h>
#include <stdlib.h>

#define Sum(a,b) a+b

void main(void) {
    int a = 5, b = 10, c;
    c = Sum(a, b);
    printf("c=%d\n", c);
    /*  system("pause");  */
}
