/*
    動態產生3維陣列
*/

#include  <stdio.h>
#include  <stdlib.h>

int main(void) {
    int (*x)[4][3];
    int  nx = 5;

    x = calloc(nx * 4 * 3, sizeof(int));    /* 確保 */

    if (x == NULL) {
        puts("儲存空間確保失敗。");
    } else {
        int  i, j, k;

        for (i = 0; i < nx; i++)
            for (j = 0; j < 4; j++)
                for (k = 0; k < 3; k++) {
                    printf("x[%d][%d][%d] = %d\n", i, j, k, x[i][j][k]);
                }

        free(x);                            /* 釋放 */
    }

    system("PAUSE");
    return (0);
}
