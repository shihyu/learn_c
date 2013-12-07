/***************************
    檔名:ch4_12.c
    功能:[*]參數
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int data1 = 1234;
    printf("請輸入整數data1的值:");
    scanf("%*d", &data1);
    printf("======正在輸出=======\n");
    printf("data1=%d\n", data1);
    /*  system("pause");  */
}
