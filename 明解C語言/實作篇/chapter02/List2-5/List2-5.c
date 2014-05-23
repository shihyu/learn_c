/*
    unsigned char與int的運算
*/

#include  <stdio.h>
#include  <limits.h>

int main(void) {
    int  x;
    unsigned char  ch = UCHAR_MAX;  /*無號char的最大值*/

    printf("ch的值為%d。\n", ch);

    x = ch + 1;

    printf("\nx = ch + 1;\n");
    printf("x的值為%d。\n", x);

    x = ++ch;

    printf("\nx = ++ch;\n");
    printf("x的值為%d。\n", x);

    system("PAUSE");
    return (0);
}
