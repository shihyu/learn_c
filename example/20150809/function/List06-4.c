/*
求連乘積（幾次方）
*/
#include  <stdio.h>

/*---傳回dx的no連乘積---*/
double power(double dx, int no) {
    int  i;
    double  tmp = 1.0;

    for (i = 1; i <= no; i++) {
        tmp *= dx;
    }

    return (tmp);
}

int main(void) {
    int n;
    double  x;

    printf("請輸入一個實數：");
    scanf("%lf", &x);
    printf("請輸入一個整數：");
    scanf("%d",  &n);

    printf("%.2f的%d次方為%.2f。\n", x, n, power(x, n));

    return (0);
}
