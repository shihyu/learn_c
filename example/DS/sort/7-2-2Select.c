/*=========================================================

       7-2-2節 選擇排序法

          Select_Sort()         選擇排序法函式
          a[ARR_NUM]            欲排序之資料
          ARR_NUM               欲排序之資料數目(陣列大小)

  =========================================================
*/

#include <stdio.h>

#define ARR_NUM 9
void Select_Sort(int [], int);

int main(void) {
    int a[ARR_NUM] = {37, 41, 19, 81, 41, 25, 56, 61, 49}, i;
    printf("排序前 (before sorting)\n");

    for (i = 0; i < ARR_NUM; i++) {
        printf(" %d", a[i]);
    }

    Select_Sort(a, ARR_NUM);
    printf("\n排序後 ( after sorting )\n");

    for (i = 0; i < ARR_NUM; i++) {
        printf(" %d", a[i]);
    }

    printf("\n");
    return 0;
}
void Select_Sort(int a[], int n) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;

        for (j = i + 1; j < n ; j++)
            if (a[j] < a[min]) {
                min = j;
            }

        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}
