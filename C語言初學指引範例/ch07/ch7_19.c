/***************************
    檔名:ch7_19.c
    功能:二分搜尋法
 ***************************/

#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int Target, int* arr, int arr_index) {
    int Low, Upper, m;
    Low = 0;
    Upper = arr_index - 1;

    while (Low <= Upper) {
        m = (Low + Upper) / 2; /* 計算中間位置 */

        if (arr[m] == Target) { /* 找到了 */
            return m;
        } else {
            if (arr[m] > Target) { /* Target位於上半部 */
                Upper = m - 1;
            } else {           /* Target位於下半部 */
                Low = m + 1;
            }
        }
    }

    return -1;
}

void main(void) {
    int work[8] = {33, 41, 52, 54, 63, 74, 79, 86};
    int FindNumber, location;
    printf("請輸入您要找的數值:");
    scanf("%d", &FindNumber);
    location = BinarySearch(FindNumber, work, 8);

    if (location == -1) {
        printf("在陣列中找不到要找的數值\n");
    } else {
        printf("數值%d位於work[%d]\n", FindNumber, location);
    }

    /*  system("pause");  */
}
