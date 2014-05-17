#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANGE 10

void show(int* arr, int row, int col) {
    int i, j;

    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            printf("%d ", *(arr + col * i + j));
        }

        printf("\n");
    }

    printf("\n");
}

int main(int argc, char const* argv[]) {
    int numRows, numCols;
    int* matrix_a;
    int* matrix_b;
    int* matrix_c;

    printf("Enter values for numRows and numCols\n");
    scanf("%d", &numRows);
    scanf("%d", &numCols);

    matrix_a = malloc(numRows * numCols * sizeof(int));
    matrix_b = malloc(numRows * numCols * sizeof(int));
    matrix_c = malloc(numRows * numCols * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            *(matrix_a + numCols * i + j) = rand() % RANGE;
            *(matrix_b + numCols * i + j) = rand() % RANGE;
            *(matrix_c + numCols * i + j) = rand() % RANGE;
        }
    }

    show(matrix_a, numRows, numCols);
    show(matrix_b, numRows, numCols);

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (*(matrix_a + numCols * i + j) - * (matrix_b + numCols * i + j) >= 0) {
                *(matrix_c + numCols * i + j) = *(matrix_a + numCols * i + j) - *(matrix_b + numCols * i + j);
            } else {
                *(matrix_c + numCols * i + j) = 0;
            }
        }
    }

    show(matrix_c, numRows, numCols);

    free(matrix_a) ; //釋放雙重指標
    free(matrix_b) ; //釋放雙重指標
    free(matrix_c) ; //釋放雙重指標

    return 0;
}

