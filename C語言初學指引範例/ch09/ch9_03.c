/*******************************
    檔名:ch9_03.c
    功能:全域變數與區域變數同名
 *******************************/

#include <stdio.h>
#include <stdlib.h>

int a = 10;

void func1(void) {
    int a = 5;
    a++;
    printf("func1的 a=%d\n", a);
}

void func2(void) {
    a += 5;
    printf("全域的 a=%d\n", a);
}

void main(void) {
    int a = 20;
    a++;
    printf("main的 a=%d\n", a);
    func1();
    func2();
    system("pause");
}
