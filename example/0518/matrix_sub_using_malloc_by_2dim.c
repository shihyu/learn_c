#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RANGE 10

void show(int** arr, int row, int col) {
    int i, j;

    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }

    printf("\n");
}

int main(int argc, char const* argv[]) {
    int numRows, numCols;
    int** matrix_a;
    int** matrix_b;
    int** matrix_c;

    printf("Enter values for numRows and numCols\n");
    scanf("%d", &numRows);
    scanf("%d", &numCols);

    /* Create space for first array (array of pointers to each row). */
    matrix_a = (int**) malloc(numRows * sizeof(int*)); //配置雙重指標指向(int*)型態 * numRows個
    matrix_b = (int**) malloc(numRows * sizeof(int*)); //配置雙重指標指向(int*)型態 * numRows個
    matrix_c = (int**) malloc(numRows * sizeof(int*)); //配置雙重指標指向(int*)型態 * numRows個

    for (int i = 0 ; i < numRows ; ++i) {
        matrix_a[i] = (int*) malloc(numCols * sizeof(int)); //以for迴圈配置n個一重指標指向int空間
        matrix_b[i] = (int*) malloc(numCols * sizeof(int)); //以for迴圈配置n個一重指標指向int空間
        matrix_c[i] = (int*) malloc(numCols * sizeof(int)); //以for迴圈配置n個一重指標指向int空間
    }

    srand(time(NULL));

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            matrix_a[i][j] = rand() % RANGE;
            matrix_b[i][j] = rand() % RANGE;
        }
    }

    show(matrix_a, numRows, numCols);
    show(matrix_b, numRows, numCols);

    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (matrix_a[i][j] - matrix_b[i][j] >= 0) {
                matrix_c[i][j] = matrix_a[i][j] - matrix_b[i][j];
            } else {
                matrix_c[i][j] = 0;
            }
        }
    }

    show(matrix_c, numRows, numCols);

    // do something with arrayPtr[i][j]
    for (int i = 0 ; i < numRows ; ++i) {
        free(matrix_a[i]) ;  // 以迴圈釋放n個一重指標指向的空間
        free(matrix_b[i]) ;  // 以迴圈釋放n個一重指標指向的空間
        free(matrix_c[i]) ;  // 以迴圈釋放n個一重指標指向的空間
    }

    free(matrix_a) ; //釋放雙重指標
    free(matrix_b) ; //釋放雙重指標
    free(matrix_c) ; //釋放雙重指標

    return 0;
}

