/***************************
    檔名:ch7_18.c
    功能:循序搜尋法
 ***************************/

#include <stdio.h>
#include <stdlib.h>

int SeqSearch(int Target, int* arr, int arr_index) {
    int i;

    for (i = 0; i < arr_index; i++)
        if (Target == arr[i]) {    /* 找到了 */
            return i;
        }

    return -1;                  /* 完全找不到 */
}

void main(void) {
    int work[11] = {43, 23, 67, 27, 39, 15, 39, 37, 57, 26, 14};
    int FindNumber, location;
    printf("請輸入您要找的數值:");
    scanf("%d", &FindNumber);
    location = SeqSearch(FindNumber, work, 11);

    if (location == -1) {
        printf("在陣列中找不到要找的數值\n");
    } else {
        printf("數值%d位於work[%d]\n", FindNumber, location);
    }

    /*  system("pause");  */
}
