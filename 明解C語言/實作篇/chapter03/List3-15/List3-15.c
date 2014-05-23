/*
    對動態產生的整數代入值並顯示
*/

#include  <stdio.h>
#include  <stdlib.h>

int main(void) {
    int*  x;

    x = calloc(1, sizeof(int));             /* 確保 */

    if (x == NULL) {
        puts("儲存空間確保失敗。");
    } else {
        *x = 100;
        printf("*x = %d\n", *x);
        free(x);                            /* 釋放 */
    }

    system("PAUSE");
    return (0);
}
