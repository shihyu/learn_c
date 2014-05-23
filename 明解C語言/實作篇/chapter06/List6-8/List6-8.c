/*
    求出3次方值(將標準標頭引入)
*/

#include  <math.h>
#include  <stdio.h>

int main(void) {
    double  x;

    printf("請輸入實數值 : ");
    scanf("%lf", &x);

    printf("該數的3次方為%.3f。\n", pow(x, 3));

    system("PAUSE");
    return (0);
}
