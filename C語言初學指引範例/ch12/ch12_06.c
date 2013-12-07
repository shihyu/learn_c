/*******************************
    檔名:ch12_06.c
    功能:實現快速排序法
 *******************************/
#include <stdlib.h>
#include <stdio.h>

void QuickSort(int* arr, int left, int right) {
    int i, j, work, temp;

    if (left < right) {   /* 只有left<right時才需要排序 */
        i = left + 1;
        j = right;
        work = arr[left];   /* 設定基數為work */

        do {               /*每一回合的詳細步驟*/
            while (arr[i] < arr[left]) {
                i++;
            }

            while (arr[j] > arr[left]) {
                j--;
            }

            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            } else {
                arr[left] = arr[j];
                arr[j] = work;
                break;
            }
        } while (1);

        QuickSort(arr, left, j - 1); /*遞迴呼叫,排序左邊資料*/
        QuickSort(arr, j + 1, right); /*遞迴呼叫,排序右邊資料*/
    }
}

void main(void) {
    int C[10] = {24, 7, 36, 2, 65, 12, 58, 16, 47, 18};
    int i;
    QuickSort(C, 0, 10);

    for (i = 0; i <= 9; i++) {
        printf("%d\t", C[i]);
    }

    /* system("pause"); */
}
