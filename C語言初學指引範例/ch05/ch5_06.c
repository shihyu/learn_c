/***************************
    檔名:ch5_06.c
    功能:?條件運算子的練習
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int Ans = 38; /* 答案為38 */
    int Guess;
    printf("請猜一個1~99的號碼:");
    scanf("%d", &Guess);

    if (Guess == Ans) {
        printf("恭喜您猜到了,獎品是一包乖乖.\n");
    } else {
        (Guess > Ans) ? printf("您猜得太大了\n") : printf("您猜得太小了\n");
    }

    /*  system("pause");  */
}
