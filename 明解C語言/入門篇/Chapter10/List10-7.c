/*
求兩整數之和與差
*/

#include  <stdio.h>

/*---把n1、n2之和與差存入sum及diff---*/
void sum_diff(int n1, int n2, int* sum, int* diff) {
    *sum  = n1 + n2;
    *diff = (n1 > n2) ? n1 - n2 : n2 - n1;
}

int main(void) {
    int  na, nb;
    int  wa = 0, sa = 0;

    puts("請輸入兩個整數：");
    printf("整數A：");
    scanf("%d", &na);
    printf("整數B：");
    scanf("%d", &nb);

    sum_diff(na, nb, &wa, &sa);

    printf("兩數和為%d。\n兩數差為%d。\n", wa, sa);

    return (0);
}
