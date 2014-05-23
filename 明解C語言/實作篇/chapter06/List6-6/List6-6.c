/*
    求出3次方值(K&R風格:不會有預期的結果)
*/

#include  <stdio.h>

extern double pow();

int main(void) {
    double  x;

    printf("請輸入實數值 : ");
    scanf("%lf", &x);

    printf("該數的3次方為%.3f。\n", pow(x, 3));

    system("PAUSE");
    return (0);
}
