#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANGE 100
#define M 5
#define N 5

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

int main(int argc, char const* argv[]) {
    int matrix_a[M][N];
    int matrix_b[M][N];
    int matrix_c[M][N];

    srand(time(NULL));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix_a[i][j] = rand() % RANGE;
            matrix_b[i][j] = rand() % RANGE;
        }
    }

    show(M, N, matrix_a);
    show(M, N, matrix_b);

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix_c[i][j] = (matrix_a[i][j] - matrix_b[i][j] > 0) ? matrix_a[i][j] - matrix_b[i][j] : 0;
        }
    }

    show(M, N, matrix_c);
    return 0;
}

