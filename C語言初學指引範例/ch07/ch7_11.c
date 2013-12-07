/******************************
    檔名:ch7_11.c
    功能:srand與rand函式練習
 ******************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void) {
    int i;
    srand((unsigned) time(NULL));

    for (i = 1; i <= 6; i++) {
        printf("第%d個隨機亂數為%d\n", i, rand());
    }

    /*  system("pause");  */
}
