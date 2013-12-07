/***************************
    檔名:ch5_02.c
    功能:if敘述的練習
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int x;
    char* str1;
    str1 = "您輸入的是正數或0";
    printf("請輸入一個整數:");
    scanf("%d", &x);

    if (x < 0) {
        str1 = "您輸入的是負數";
    }

    printf("%s\n", str1);
    /*  system("pause");  */
}
