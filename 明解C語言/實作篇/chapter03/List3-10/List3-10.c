/*
    將陣列的全部元素加總(不傳遞元素數)
*/

#include  <stdio.h>

/*--- 將哨兵9999之前的元素加總 ---*/
int sumup(int z[]) {
    int  i;
    int  sum = 0;

    for (i = 0; z[i] != 9999; i++) {
        sum += z[i];
    }

    return (sum);
}

int main(void) {
    int  goukei;                            /* 合計 */
    int  x[6];
    int  i;
    int  nx = sizeof(x) / sizeof(x[0]); /* 陣列x的元素個數 */

    for (i = 0; i < nx - 1; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);

        if (x[i] == 9999) {
            break;    /* 輸入結束 */
        }
    }

    if (i == nx - 1) {      /* 若沒有被輸入9999的話，則將 */
        x[i] = 9999;    /*最後一個元素設為9999        */
    }

    goukei = sumup(x);
    printf("合計 = %d\n", goukei);

    system("PAUSE");
    return (0);
}
