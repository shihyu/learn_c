/*******************************
    檔名:ch9_07.c
    功能:static區域變數
 *******************************/

#include <stdio.h>
#include <stdlib.h>

void func1(void) {
    static int var1 = 100;
    printf("var1 = %d\n", var1);
    var1 = var1 + 1;
    printf("var1 = %d\n", var1);
}

void func2(void) {
    auto int var2;
    var2 = 0;
    var2++;
}

void main(void) {
    func1();
    func2();
    printf("==============\n");
    func1();
    /*  system("pause");  */
}
