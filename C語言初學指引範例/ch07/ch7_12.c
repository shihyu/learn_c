/*******************************
    檔名:ch7_12.c
    功能:產生6個1~42的隨機亂數
 *******************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void) {
    int lotto[6];
    int i;
    srand((unsigned) time(NULL));

    for (i = 1; i <= 6; i++) {
        lotto[i - 1] = rand() % 42 + 1;
        printf("第%d個號碼為%d\n", i, lotto[i - 1]);
    }

    /*  system("pause");  */
}
