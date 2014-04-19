#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 8


void show(int (*arr)[3]) {
    int i, j;

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }

}

int main(int argc, char *argv[]) {
    int matrix_a[3][3];
    int matrix_b[3][3];
    int matrix_c[3][3];
    int i, j, k;

    srand(time(NULL)); // 設定不同的亂數種子

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix_a[i][j] = rand() % RANGE;
            matrix_b[i][j] = rand() % RANGE;

        }
    }

    show(matrix_a);
    printf("\n");
    show(matrix_b);
    printf("\n");

#if 0

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix_c[i][j] = 0;
        }
    }

#endif

    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            matrix_c[i][j] = 0;

            for (k = 0; k < 3; ++k) {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }

    show(matrix_c);

    return 0;
}
