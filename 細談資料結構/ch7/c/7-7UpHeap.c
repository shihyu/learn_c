/*=========================================================

       7-7節 Up_Heap 建立堆積

          Construct_by_Insert() 將陣列調整成堆積
          Up_Heap()             調整堆積,以符合特性
          a[ARR_NUM]            欲排序之資料
          ARR_NUM               欲排序之資料數目(陣列大小)

  =========================================================
*/

#include <stdio.h>

#define ARR_NUM 10

void Construct_by_Insert(int [], int);
void Up_Heap(int [], int);

void main(void) {
    int a[ARR_NUM] = {38, 72, 67, 41, 39, 72, 37, 25, 66, 73}, i;
    printf("建立堆積前 ( before adjusting ):\n");

    for (i = 0; i < ARR_NUM; i++) {
        printf(" %d", a[i]);
    }

    Construct_by_Insert(a, ARR_NUM);
    printf("\n建立堆積後 ( after adjusting ):\n");

    for (i = 0; i < ARR_NUM; i++) {
        printf(" %d", a[i]);
    }

    printf("\n");
}


/*將a[k]往上調整,以符合heap特性*/
void Up_Heap(int a[], int k) {
    int up;
    up = a[k];

    while (((k - 1) / 2 >= 0) && (a[(k - 1) / 2] < up)) { /*與父節點比較*/
        a[k] = a[(k - 1) / 2]; /* 父節點下來*/
        k = (k - 1) / 2 ;

        if (k == 0) {
            break;
        }
    }

    a[k] = up;
}

/*用插入的方式建立堆積 a[0 ~ n-1]*/
void Construct_by_Insert(int a[], int n) {
    int k;

    for (k = 1; k < n; k++) {
        Up_Heap(a, k);
    }
}
