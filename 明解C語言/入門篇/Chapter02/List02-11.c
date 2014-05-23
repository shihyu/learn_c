/*
    計算三個整數之和與平均值再輸出
*/

#include  <stdio.h>

int main(void) {
    int na, nb, nc;
    int sum;            /*合計值*/
    double ave;         /*平均值*/

    puts("請輸入三個整數。");
    printf("整數A：");
    scanf("%d", &na);
    printf("整數B：");
    scanf("%d", &nb);
    printf("整數C：");
    scanf("%d", &nc);

    sum = na + nb + nc;
    ave = (double)sum / 3;           /* cast */

    printf("其和為%5d。\n",       sum);      /* 99999 */
    printf("其平均值為%5.1f。\n", ave);      /* 999.9 */

    return (0);
}

