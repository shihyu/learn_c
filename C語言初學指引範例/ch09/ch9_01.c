/*******************************
    檔名:ch9_01.c
    功能:全域變數與區域變數
 *******************************/

#include <stdio.h>
#include <stdlib.h>

int a = 10;

void func1(void) {
    int b = 5;
    a = a + 1;
    b = b + 1;
    /* c=c+1; */  /* 這是錯的敘述  */
    printf("b=%d\n", b);
}

void main(void) {
    int c = 20;
    a = a + 1;
    /* b=b+1; */  /*  這是錯的敘述  */
    c = c + 1;
    printf("a=%d\n", a);
    func1();
    printf("a=%d\n", a);
    printf("c=%d\n", c);
    /*  system("pause");  */
}
