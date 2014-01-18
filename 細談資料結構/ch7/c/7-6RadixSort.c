/*=========================================================

      7-6節 基數排序法

          Radix_Sort()          基數排序法函式
          get_key()             取得特定位數值(如個位,十位)
          a[ARR_NUM]            欲排序之資料
          ARR_NUM               欲排序之資料數目(陣列大小)

  =========================================================
*/

#include <stdio.h>
#include <math.h>

#define ARR_NUM 9

int count[10];
void Radix_Sort(int [], int [], int , int , int);
int get_key(int, int, int);

void main(void) {
    int a[ARR_NUM] = {137, 219, 532, 655, 422, 164, 98, 422, 334}, b[ARR_NUM], i;
    printf("排序前( before sorting ):\n");

    for (i = 0; i < ARR_NUM; i++) {
        printf(" %d", a[i]);
    }

    Radix_Sort(a, b, ARR_NUM, 10, 3);
    printf("\n排序後 ( after sorting ):\n");

    for (i = 0; i < ARR_NUM; i++) {
        printf(" %d", a[i]);
    }

    printf("\n");
}

/*排序 a[0]..a[n-1],鍵值只有0..m-1 共m種可能 每個鍵值有k位數*/
void Radix_Sort(int a[], int b[], int n, int m, int k) {
    int i, j, d, pass;

    for (pass = 0; pass < k; pass++) {
        for (j = 0; j < m; j++) {
            count[j] = 0;
        }

        for (i = 0; i < n; i++) {       /*計算各鍵值出現次數*/
            d = get_key(a[i], pass, m);
            count[d]++;
        }

        for (j = 1; j < m; j++) {
            count[j] = count[j] + count[j - 1];
        }

        for (i = n - 1; i >= 0; i--) {  /*分配*/
            d = get_key(a[i], pass, m);
            b[count[d] - 1] = a[i];
            count[d]--;
        }
    }

    for (i = 0; i < n; i++) {    /*拷貝回a[]*/
        a[i] = b[i];
    }
}

int get_key(int a, int pass, int m) {
    a = a / pow(m, pass);
    a = a % m;
    return (a);
}
