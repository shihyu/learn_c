/*********************************
    檔名:ch7_05.c
    功能:無傳入引數及回傳值的函式
 *********************************/

#include <stdio.h>
#include <stdlib.h>

void print99(void); /* 函式宣告 */
void print99(void) { /* 函式定義 */
    int i, j;

    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9; j++) {
            printf("%d*%d=%d\t", i, j, i * j);
        }

        printf("\n");
    }
}

void main(void) {
    printf("以下是常見的九九乘法表\n");
    print99();         /* 函式呼叫 */
    /*  system("pause");  */
}
