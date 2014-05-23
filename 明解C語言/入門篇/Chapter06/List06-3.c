/*
求出兩整數平方值之差
*/
#include  <stdio.h>

/*---傳回平方值---*/
int sqr(int x) {
    return (x * x);
}

/*---傳回差 ---*/
int diff(int x, int y) {
    return (x > y ? x - y : y - x);
}

int main(void) {
    int      kx, ky, kx2, ky2;

    puts("請輸入兩個整數：");
    printf("整數kx：");
    scanf("%d", &kx);
    printf("整數ky：");
    scanf("%d", &ky);

    kx2 = sqr(kx);        /* kx的平方 */
    ky2 = sqr(ky);        /* ky的平方 */
    printf("kx的平方值與ky的平方值之差為%d。\n", diff(kx2, ky2));

    return (0);
}
