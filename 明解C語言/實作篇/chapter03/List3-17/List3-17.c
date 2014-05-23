/*
    動態地產生整數陣列
*/

#include  <stdio.h>
#include  <stdlib.h>

int main(void) {
    int*  x;
    int  i, nx;

    printf("請問要產生幾個元素數的陣列 : ");
    scanf("%d", &nx);

    x = calloc(nx, sizeof(int));                    /* 確保 */

    if (x == NULL) {
        puts("儲存空間確保失敗。");
    } else {
        for (i = 0; i < nx; i++) {                  /* 代入值 */
            x[i] = i;
        }

        for (i = 0; i < nx; i++) {                  /* 顯示值 */
            printf("x[%d] = %d\n", i, x[i]);
        }

        free(x);                                    /* 釋放 */
    }

    system("PAUSE");
    return (0);
}
