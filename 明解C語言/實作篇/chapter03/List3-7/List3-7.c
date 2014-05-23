/*
    將陣列全元素的值加總(錯誤版)
*/

#include  <stdio.h>

/*--- 傳回陣列z的全元素的加總(錯誤) ---*/
double sumup(double z[n]) {
    int     i;
    double  sum = 0.0;

    for (i = 0; i < n; i++) {
        sum += z[i];
    }

    return (sum);
}

int main(void) {
    double  goukei;                         /* 加總 */
    double  x[5];
    int  i;
    int  nx = sizeof(x) / sizeof(x[0]); /*陣列x的元素個數*/

    for (i = 0; i < nx; i++) {
        printf("x[%d] : ", i);
        scanf("%lf", &x[i]);
    }

    goukei = sumup(x);
    printf("合計=%f\n", goukei);

    return (0);
}
