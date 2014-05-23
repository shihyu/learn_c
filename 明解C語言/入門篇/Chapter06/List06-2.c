/*
傳回三整數中最大值的函數
*/

#include  <stdio.h>

/*---請輸入三個整數。---*/
int max3(int x, int y, int z) {
    int  max = x;

    if (y > max) {
        max = y;
    }

    if (z > max) {
        max = z;
    }

    return (max);
}

int main(void) {
    int  na, nb, nc;

    puts("請輸入三個整數：");
    printf("整數1：");
    scanf("%d", &na);
    printf("整數2：");
    scanf("%d", &nb);
    printf("整數3：");
    scanf("%d", &nc);

    printf("三者中最大值為%d。\n", max3(na, nb, nc));

    return (0);
}
