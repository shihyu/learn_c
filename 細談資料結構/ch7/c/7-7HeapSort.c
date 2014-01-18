/*=========================================================

       7-7節 堆積排序法

          Heap_Sort()           堆積排序法函式
          Construct_by_Adjust() 將陣列調整成堆積
          Down_Heap()            調整堆積,以符合特性
          a[ARR_NUM]            欲排序之資料
          ARR_NUM               欲排序之資料數目(陣列大小)

  =========================================================
*/

#include <stdio.h>

#define ARR_NUM 9

void Heap_Sort(int [], int);
void Construct_by_Adjust(int [], int);
void Down_Heap(int [], int, int);

void main(void) {
    int a[ARR_NUM] = {37, 41, 19, 81, 41, 25, 56, 61, 49}, i;
    printf("排序前 ( before sorting ):\n");

    for (i = 0; i < ARR_NUM; i++) {
        printf(" %d", a[i]);
    }

    Heap_Sort(a, ARR_NUM);
    printf("\n排序後 ( after sorting ):\n");

    for (i = 0; i < ARR_NUM; i++) {
        printf(" %d", a[i]);
    }

    printf("\n");
}

void Heap_Sort(int a[], int n) {
    int temp;
    Construct_by_Adjust(a, n);   /*建立堆積*/

    while (n > 1) {
        temp = a[n - 1];        /*樹根跟最後一個元素交換*/
        a[n - 1] = a[0];
        a[0] = temp;
        n--;
        Down_Heap(a, n, 0);      /*調整成heap*/
    }
}

/*用調整的方式建立堆積 a[n]*/
void Construct_by_Adjust(int a[], int n) {
    int k;

    for (k = n / 2 - 1; k >= 0; k--) {
        Down_Heap(a, n, k);
    }
}

/*將a[k]往下調整,以符合heap特性*/
void Down_Heap(int a[], int n, int k) {
    int j, up;
    up = a[k];

    while (k < n / 2) {          /*a[k]必須有子節點*/
        j = 2 * k + 1;          /*a[k]之左兒子a[j]*/

        if (j + 1 < n && a[j] < a[j + 1]) {
            j++;    /*若右兒子較大且存在;a[j]為a[k]之右兒子*/
        }

        if (up >= a[j]) {
            break;    /*大於大兒子*/
        }

        a[k] = a[j];            /*大兒子上來*/
        k = j;
    }

    a[k] = up;
}
