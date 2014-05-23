/*
傳回兩整數中較大者之值的函數
*/
#include  <stdio.h>

/*---傳回較大者之值---*/
int maxof(int x, int y) {
    if (x > y) {
        return (x);
    } else {
        return (y);
    }
}

int main(void) {
    int  na, nb;

    puts("請輸入兩個整數：");
    printf("整數1：");
    scanf("%d", &na);
    printf("整數2：");
    scanf("%d", &nb);

    printf("兩者中較大者之值為%d。\n", maxof(na, nb));

    return (0);
}
