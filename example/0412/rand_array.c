#include <stdio.h>
#include <stdlib.h>

#define RANGE 10


void show(int (*arr)[3])
{
    int i, j;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

}

int main(int argc, char *argv[])
{
    int matrix_a[3][3];
    int matrix_b[3][3];
    int matrix_c[3][3];
    int i, j;

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



    return 0;
}
