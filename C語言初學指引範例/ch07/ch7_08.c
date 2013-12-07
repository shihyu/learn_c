/***************************
    檔名:ch7_08.c
    功能:return返回
 ***************************/

#include <stdio.h>
#include <stdlib.h>

int func1(void) {
    int a = 5, b = 7;
    a++;
    return a + b;
    a++;
    return a + b;
    a++;
    return a + b;
}

void main(void) {
    int k;
    k = func1();
    printf("k=%d\n", k);
    /*  system("pause");  */
}
