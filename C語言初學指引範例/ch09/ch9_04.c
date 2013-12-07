/*******************************
    檔名:ch9_04.c
    功能:自訂程式區段
 *******************************/

#include <stdio.h>
#include <stdlib.h>

int var5 = 50;

void func1(void) {
    int var1 = 10;
    printf("var1=%d\n", var1);
    {
        int var2 = 20;
        printf("var2=%d\n", var2);
    }
    printf("var5=%d\n", var5);
}

void main(void) {
    int var3 = 30;
    func1();
    printf("var3=%d\n", var3);
    {
        int var4 = 40;
        printf("var4=%d\n", var4);
    }
    printf("var5=%d\n", var5);
    /*  system("pause");  */
}
