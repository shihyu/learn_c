/*******************************
    檔名:ch8_01.c
    功能:取址運算子與指標運算子
 *******************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int a = 50, b;
    int* ptr;
    printf("a=%d\n", a);
    ptr = &a;        /*  將ptr指向a  */
    printf("*ptr=%d\n", *ptr);
    b = *ptr;        /*  將a的值(ptr指向的值)設定給b  */
    printf("b=%d\n", b);
    /*  system("pause");  */
}
