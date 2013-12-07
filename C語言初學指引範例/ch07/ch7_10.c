/***************************
    檔名:ch7_10.c
    功能:rand函式練習
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int i;

    for (i = 1; i <= 6; i++) {
        printf("第%d個隨機亂數為%d\n", i, rand());
    }

    /*  system("pause");  */
}
