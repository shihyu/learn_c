/*******************************
    檔名:ch12_05.c
    功能:實現插入排序法
 *******************************/
#include <stdlib.h>
#include <stdio.h>

void InsertionSort(int* arr, int arr_index) {
    int i, j, work;

    for (i = 1; i < arr_index; i++) {
        work = arr[i];

        for (j = i - 1; ((j >= 0) && (work < arr[j])); j--) {
            arr[j + 1] = arr[j];
        }

        arr[j + 1] = work;
    }
}

void main(void) {
    int B[5] = {24, 7, 36, 2, 15};
    int i;
    InsertionSort(B, 5);

    for (i = 0; i <= 4; i++) {
        printf("%d\t", B[i]);
    }

    /* system("pause"); */
}
