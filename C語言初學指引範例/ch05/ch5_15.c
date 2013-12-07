/***************************
    檔名:ch5_15.c
    功能:多層for迴圈的示範
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int i, j;

    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9; j++) {
            printf("%d*%d=%d\t", i, j, i * j);
        }

        printf("\n");
    }

    /*  system("pause");  */
}
