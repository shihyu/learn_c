/*
  由後而前重新排列非負數的整數
*/

#include  <stdio.h>

int main(void) {
    int  num;

    do {
        printf("請輸入一個非負數的整數：");
        scanf("%d", &num);

        if (num < 0) {
            puts("\a請勿輸入負數！");
        }
    } while (num < 0);

    /* num大於0 */
    printf("由後而前重新排列的新數是");

    do {
        printf("%d", num % 10);                     /* 輸出最末位之值 */
        num = num / 10;                                  /* 小數點往左移一位 */
    } while (num > 0);

    puts("。");

    return (0);
}
