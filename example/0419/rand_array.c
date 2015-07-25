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
    printf("\n");
}


void generator_data(int row, int col, int ar[][col]) {
    int i, j;

    srand(time(NULL)); // 設定不同的亂數種子

    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            ar[i][j] = rand() % RANGE;

        }
    }
}


int main(int argc, char *argv[]) {
    int matrix_a[M][K]; // 3 x 2
    int matrix_b[K][N]; // 2 X 4
    int matrix_c[M][N] = {0}; // 3 X 4
    int i, j, k;

    generator_data(M,K,matrix_a);
    generator_data(K,N,matrix_b);

    show(M, K, matrix_a);
    show(K, N, matrix_b);

    for (i = 0; i < M; ++i) {
        for (j = 0; j < N; ++j) {

            for (k = 0; k < K; k++) {
                matrix_c[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }

    show(M, N, matrix_c);

    return 0;
}
