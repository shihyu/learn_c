/******************************
    檔名:ch7_07.c
    功能:函式宣告與定義的合併
 ******************************/

#include <stdio.h>
#include <stdlib.h>

void func1(void) { /* func1函式定義(省略函式宣告) */
    printf("func1函式正在執行中...\n");
}

void func2(void) { /* func2函式定義(省略函式宣告) */
    printf("func2函式正在執行中...\n");
}

void main(void) {
    func1();
    func2();
    /*  system("pause");  */
}

