#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 5

void bubblesort(int *data, int n)
{
    int i, j, temp;
    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j <= i - 1; j++)
        {
            if (data[j] < data[j + 1])
            {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void show(int arr[])
{
    int i;
    for (i = 0; i < RANGE; ++i) {
            printf("%d ",arr[i]);
    }

}

int main(int argc, char *argv[])
{
#if 1
    int matrix_a[RANGE] = {10, 20, 30 , 40 ,50};
#else
    int matrix_a[RANGE];
    matrix_a[0] = 10;
    matrix_a[1] = 20;
    matrix_a[2] = 30;
    matrix_a[3] = 40;
    matrix_a[4] = 50;
#endif
#if 0
    int i;

    srand(time(NULL)); // 設定不同的亂數種子

    for (i = 0; i < RANGE; ++i) {
            matrix_a[i] = rand() % 10000;
    }
#endif
    show(matrix_a);

    printf("\n");
    bubblesort(matrix_a, RANGE);
    
    show(matrix_a);

    return 0;
}
