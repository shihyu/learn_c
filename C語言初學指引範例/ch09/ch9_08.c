/*******************************
    檔名:ch9_08.c
    功能:static區域變數
 *******************************/

#include <stdio.h>
#include <stdlib.h>

void func1(void) {
    /* printf("var1 = %d\n",var1); */
    {
        static int var1 = 100;
        var1 = var1 + 1;
        printf("var1 = %d\n", var1);
    }
    /* printf("var1 = %d\n",var1); */
}

void main(void) {
    func1();
    printf("==============\n");
    func1();
    /*  system("pause");  */
}
