/***************************
    檔名:ch7_09.c
    功能:無回傳值的錯誤
 ***************************/

#include <stdio.h>
#include <stdlib.h>

int func1(void) {
    printf("func1函式正在執行中...\n");
}

void main(void) {
    int a = 1;
    a = func1();
    printf("a=%d\n", a);
    /*  system("pause");  */
}
