/*******************************
    檔名:ch9_02.c
    功能:全域變數與區域變數
 *******************************/

#include <stdio.h>
#include <stdlib.h>

int a = 10;
void func1(void);

void main(void) {
    int c = 20;
    printf("a=%d\n", a);
    /* printf("b=%d\n",b); */  /*  這是錯的敘述  */
    func1();
    /*  system("pause");  */
}

int b = 100;

void func1(void) {
    printf("a=%d\n", a);
    printf("b=%d\n", b);
}
