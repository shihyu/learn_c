/*
    動態產生2維陣列
*/

#include  <stdio.h>
#include  <stdlib.h>

int main(void) {
    int (*x)[3];
    int  nx = 4;

    x = calloc(nx * 3, sizeof(int));    /*確保*/

    if (x == NULL) {
        puts("儲存空間確保失敗。");
    } else {
        int  i, j;

        for (i = 0; i < nx; i++)
            for (j = 0; j < 3; j++) {
                printf("x[%d][%d] = %d\n", i, j, x[i][j]);
            }

        free(x);                                /*釋放*/
    }

    system("PAUSE");
    return (0);
}
