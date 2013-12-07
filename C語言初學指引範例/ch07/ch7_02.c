/***************************
    檔名:ch7_02.c
    功能:宣告,定義,呼叫函式
 ***************************/

#include <stdio.h>
#include <stdlib.h>

double Power(double, int);

double Power(double X, int n) {
    int i;
    double PowerXn = 1;

    for (i = 1; i <= n; i++) {
        PowerXn = PowerXn * X;
    }

    return PowerXn;
}

void main(void) {
    int k;
    double Ans;
    printf("計算3.5的k次方?請輸入k=");
    scanf("%d", &k);
    Ans = Power(3.5, k);     /*  呼叫函式  */
    printf("3.5的%d次方=%f\n", k, Ans);
    /*  system("pause");  */
}
