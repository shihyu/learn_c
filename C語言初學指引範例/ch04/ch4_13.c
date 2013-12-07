/***************************
    檔名:ch4_13.c
    功能:[h|l|L]參數
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int var1 = 0, var2 = 0;
    printf("請用16進制輸入var1的值:");
    scanf("%x", &var1);
    printf("請用16進制輸入var2的值:");
    scanf("%hx", &var2);
    printf("var1==>%#x\n", var1);
    printf("var2==>%#x\n", var2);
    /*  system("pause");  */
}
