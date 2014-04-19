/*=========================================================

       7-5節 快速排序法

          Quick_Sort()          快速排序法函式
          partition()           分割陣列函式
          a[ARR_NUM]            欲排序之資料
          ARR_NUM               欲排序之資料數目(陣列大小)

  =========================================================
*/

#include <stdio.h>

#define ARR_NUM 9
void Quick_Sort(int [], int, int);
int Partition(int [], int, int);

int main(void) {
    int a[ARR_NUM] = {37, 41, 19, 81, 41, 25, 56, 61, 49}, i;
    printf("排序前 ( before sorting ):\n");

    for (i = 0; i < ARR_NUM; i++) {
        printf(" %d", a[i]);
    }

    Quick_Sort(a, 0, ARR_NUM - 1);
    printf("\n排序後 ( after sorting ):\n");

    for (i = 0; i < ARR_NUM; i++) {
        printf(" %d", a[i]);
    }

    printf("\n");
    return 0;
}

/*快速排序法*/
void Quick_Sort(int a[], int l, int r) {
    int partition_point;

    printf("l=%d\n",l);
    printf("r=%d\n",r);
    getchar();

    if (l < r) {
        partition_point = Partition(a, l, r);   /*分割*/
        Quick_Sort(a, l, partition_point - 1);  /*收拾左半部*/
        Quick_Sort(a, partition_point + 1, r);  /*收拾右半部*/
    }
}

/*對 a[l]..a[r] 進行分割,傳回分割點*/
int Partition(int a[], int l, int r) {
    int i, j, temp;

    for (i = l + 1, j = r;;) {
        while (a[i] < a[l] && i <= r) {
            i++;
        }

        while (a[j] > a[l]) {
            j--;
        }

        if (i >= j) {
            break;
        }

        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return (j);
}
