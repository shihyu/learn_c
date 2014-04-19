#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 10
#define M 3
#define N 4
#define K 2

void show(int row, int col, int ar[row][col]) {
    int i, j;

    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            printf("%d ", ar[i][j]);
        }

        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    int matrix_a[M][K];
    int matrix_b[K][N];
    int matrix_c[M][N];
    int i, j, k;

    srand(time(NULL)); // 設定不同的亂數種子

    for (i = 0; i < M; ++i) {
        for (j = 0; j < K; ++j) {
            matrix_a[i][j] = rand() % RANGE;

        }
    }

    for (i = 0; i < K; ++i) {
        for (j = 0; j < N; ++j) {
            matrix_b[i][j] = rand() % RANGE;

        }
    }

    show(M, K, matrix_a);
    printf("\n");
    show(K, N, matrix_b);
    printf("\n");

#if 1

    for (i = 0; i < M; ++i) {
        for (j = 0; j < N; ++j) {
            matrix_c[i][j] = 0;

            for (k = 0; k < K; k++) {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }

    show(M, N, matrix_c);
#endif

    return 0;
}
