/*=========================================================

       7-3節 Shell排序法

          Shell_sort()          Shell排序法函式
          a[ARR_NUM]            欲排序之資料
          ARR_NUM               欲排序之資料數目(陣列大小)

  =========================================================
*/

#include <iostream.h>

#define ARR_NUM 9
void Shell_Sort(int [], int);

void main(void) {
    int a[ARR_NUM] = {37, 41, 19, 81, 41, 25, 56, 61, 49}, i;
    cout << "排序前(before sorting ):" << endl;

    for (i = 0; i < ARR_NUM; i++) {
        cout << " " << a[i];
    }

    Shell_Sort(a, ARR_NUM);
    cout << endl << "排序後( after sorting ):" << endl;

    for (i = 0; i < ARR_NUM; i++) {
        cout << " " << a[i];
    }

    cout << endl;
}
void Shell_Sort(int a[], int n) {
    int i, j, h, up;

    for (h = 1; h <= n / 9; h = 3 * h + 1);

    for (; h > 0; h = h / 3)
        for (i = h; i < n; i++) {
            up = a[i];
            j = i;

            while (j >= h && a[j - h] > up) {
                a[j] = a[j - h];
                j = j - h;
            }

            a[j] = up;
        }
}
