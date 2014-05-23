/*
    呼叫pow函式來求出3次方的值(無法得到正確的結果)
*/

#include  <stdio.h>

int main(void) {
    double  x;

    printf("請輸入實數值 : ");
    scanf("%lf", &x);

    printf("該數的3次方為%.3f。\n", pow(x, 3.0));

    system("PAUSE");
    return (0);
}
