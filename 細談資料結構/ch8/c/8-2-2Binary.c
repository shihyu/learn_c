/*=========================================================

       8-2-2節 二分搜尋法

          bnry_Srch()           二分搜尋函式
          a[ARR_NUM]            欲搜尋之資料
          ARR_NUM               欲搜尋之資料數目(陣列大小)

  =========================================================
*/

#include <stdio.h>

#define ARR_NUM 10
int Binary_Search(int [], int , int);
void PrintArray(int [], int);

void main(void) {
    int a[ARR_NUM] = {6, 33, 39, 41, 52, 55, 69, 77, 78, 81};
    int data, locate;
    printf("陣列內容:");
    PrintArray(a, ARR_NUM);
    printf("\n請輸入欲搜尋之資料內容 => ");
    scanf("%d", &data);

    if ((locate = Binary_Search(a, ARR_NUM, data)) == -1) {
        printf("找不到資料!!!");
    } else {
        printf("找到資料 %d 於第 %d 個位置(由0算起)", data, locate);
    }

    printf("\n");
}

/*在a[0..n-1]陣列尋找鍵值key的元素,並傳回位置 ,使用binary Search*/
int Binary_Search(int a[], int n, int key) {
    int l = 0, r = n - 1, m;

    while (l <= r) {
        m = (int)(l + r) / 2;

        if (key == a[m]) {
            return (m);    /*找到,傳回位置*/
        }

        if (key > a[m]) {       /*右半部,改變左限*/
            l = m + 1;
        } else {                /*左半部,改變右限*/
            r = m - 1;
        }
    }

    return (-1);        /*失敗傳回*/
}

void PrintArray(int a[], int n) {
    int i;

    for (i = 0; i < n ; i++) {
        printf("%d ", a[i]);
    }
}

