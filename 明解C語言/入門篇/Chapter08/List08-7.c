/*
求最大公因數
*/

#include  <stdio.h>

/*---傳回vx和vy的最大公因數（vx ≧ vy）---*/
int gcdf(int vx, int vy) {
    return (vy == 0 ? vx : gcdf(vy, vx % vy));
}

/*---求vx和vy的最大公因數---*/
int gcd(int va, int vb) {
    return (va > vb ? gcdf(va, vb) : gcdf(vb, va));
}

int main(void) {
    int  n1, n2;

    puts("請輸入兩個整數。");
    printf("整數1：");
    scanf("%d", &n1);
    printf("整數2：");
    scanf("%d", &n2);

    printf("最大公因數為%d。\n", gcd(n1, n2));

    return (0);
}
