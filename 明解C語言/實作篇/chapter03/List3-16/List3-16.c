/*
    對動態產生的整數代入值並顯示(錯誤版)
*/

#include  <stdio.h>
#include  <stdlib.h>

int main(void) {
    int*  x;

    x = calloc(1, sizeof(int));                     /* 確保 */

    if (x == NULL) {
        puts("儲存空間確保失敗。");
    } else {
        printf("請輸入整數值 : ");
        scanf("%d", &x);                           /* 這裡怪怪的? */
        printf("您輸入的值為%d。\n", *x);
        free(x);                                   /* 釋放 */
    }

    system("PAUSE");
    return (0);
}
