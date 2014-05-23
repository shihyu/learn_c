/*
    將實數值轉換成被指定的位數的字串
*/

#include  <stdio.h>

int main(void) {
    int     n1, n2;
    double  x;
    char    buf[200];

    printf("請輸入實數值 : ");
    scanf("%lf", &x);

    printf("請問要轉換成至少幾位數的字串 : ");
    scanf("%d", &n1);

    printf("其中小數點以下要幾位數 : ");
    scanf("%d", &n2);

    sprintf(buf, "%*.*f", n1, n2, x);

    printf("轉換後的字串 = %s\n", buf);

    system("PAUSE");
    return (0);
}
