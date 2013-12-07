/***************************
    檔名:ch8_15.c
    功能:動態記憶體配置
 ***************************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "./lotto.h"

/**************main()**************/
int main(int argc, char* argv[]) {
    int i, special, ball_qty = 6, temp;
    int* lotto;

    if (argc > 1) {
        ball_qty = atoi(argv[1]); /* atoi須引入stdlib.h */

        if (ball_qty == 0) {
            printf("參數錯誤,例如輸入球數非數字\n");
            return -1;
        }

        if (!((ball_qty >= 1) && (ball_qty <= 41))) {
            printf("參數錯誤,例如輸入球數非1~41\n");
            return -1;
        }
    }

    lotto = (int*)malloc(sizeof(int) * ball_qty);
    generate_lotto_sort(&special, lotto, ball_qty);
    printf("樂透號碼如下.....\n");

    for (i = 0; i < ball_qty; i++) {
        if ((i % 6 == 0) && (i != 0)) {
            printf("\n");
        }

        printf("%d\t", lotto[i]);
    }

    printf("\n");
    printf("特別號:%d\n", special);
    return 1;
}
