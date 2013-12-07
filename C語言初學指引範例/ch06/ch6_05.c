/***************************
    檔名:ch6_05.c
    功能:二維陣列的練習
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int m[9][9];
    int i, j;

    for (i = 1; i <= 9; i++)
        for (j = 1; j <= 9; j++) {
            m[i - 1][j - 1] = i * j;
        }

    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9; j++) {
            printf("%d*%d=%d\t", i, j, m[i - 1][j - 1]);
        }

        printf("\n");
    }

    /*  system("pause");  */
}
