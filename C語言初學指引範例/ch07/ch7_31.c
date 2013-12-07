/***************************
    檔名:ch7_31.c
    功能:巨集包含運算式
 ***************************/

#include <stdio.h>
#include <stdlib.h>

#define Sum(a,b) a+b
#define Mul(a,b) a*b

void main(void) {
    int a = 1, b = 2, c = 3, d = 4;
    int result1, result2;
    result1 = Sum(a * b, c * d);
    result2 = Mul(a + b, c + d);
    printf("result1=%d\n", result1);
    printf("result2=%d\n", result2);
    /*  system("pause");  */
}
