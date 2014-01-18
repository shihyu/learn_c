/*=========================================================

       7-2-1節 氣泡排序法

          Bubble_Sort()         氣泡排序法函式
          a[ARR_NUM]            欲排序之資料
          ARR_NUM               欲排序之資料數目(陣列大小)

  =========================================================
*/

#include <iostream.h>

#define ARR_NUM 9
void Bubble_Sort(int [], int);
void main(void) {
    int a[ARR_NUM] = {37, 41, 19, 81, 41, 25, 56, 61, 49}, i;
    cout << "排序前 ( before sorting ):" << endl;

    for (i = 0; i < ARR_NUM; i++) {
        cout << " " << a[i];
    }

    Bubble_Sort(a, ARR_NUM);
    cout << endl << "排序後 ( after sorting ):" << endl;

    for (i = 0; i < ARR_NUM; i++) {
        cout << " " << a[i];
    }

    cout << endl;
}
void Bubble_Sort(int a[], int n) {
    int i, j, temp;

    for (i = n - 1; i > 0; i--)
        for (j = 1; j <= i; j++)
            if (a[j - 1] > a[j]) {
                temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
}
