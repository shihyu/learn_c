/*
  求某個非負數整數的位數
*/

#include  <stdio.h>

int main(void) {
    int  num;
    int  dig;           /* 位數 */

    do {
        printf("請輸入一個非負數的整數：");
        scanf("%d", &num);

        if (num < 0) {
            puts("\a請勿輸入負數！");
        }
    } while (num < 0);

    /* num大於0時往下 */
    dig = 0;

    do {
        num = num / 10;                 /* 小數點往左移一位 */
        dig = dig + 1;
    } while (num > 0);

    printf("此數字是%d位數。\n", dig);

    return (0);
}

