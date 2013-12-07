/*********************************
    檔名:ch4_14.c
    功能:getchar函式與putchar函式
 *********************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    char ch1 = 'k';
    printf("原始字元是");
    putchar(ch1);
    printf("\n請輸入一個字元:");
    ch1 = getchar();
    printf("您所輸入的字元:%c\n", ch1);
    /*  system("pause");  */
}
