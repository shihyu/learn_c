#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void main(void) {
    int* A, *B, *C;
    int i, j, m, n;
    printf("請輸入矩陣大小\n");
    printf("請輸入列數:");
    scanf("%d", &m);
    printf("請輸入行數:");
    scanf("%d", &n);

    /*************加入程式碼,以輸入A,B元素並完成C=A+B****************/

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("C[%d,%d]=%2d    ", i + 1, j + 1, C[i * n + j]);
        }

        printf("\n");
    }

    free(A);
    free(B);
    free(C);
}
