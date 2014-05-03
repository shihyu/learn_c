#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANGE 100
#define M 5
#define N 3

void show(int* arr, int row, int col) {
    int i, j;

    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            printf("%d\t", *(arr + col * i + j));
        }

        printf("\n");
    }

    printf("\n");
}

int main(int argc, char const* argv[]) {
    int* matrix_a = NULL;
    int i, j;

    srand(time(NULL));
    matrix_a = malloc(M * N * sizeof(int));

    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            *(matrix_a + N * i + j) = rand() % RANGE;  // base address + offset [0][0] ~ [4][2]   相當於 int arr[5][3]  , arr is base addrss 
        }
    }

    show(matrix_a, M, N);

    free(matrix_a);

    return 0;
}

