/* mymath.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mymath.h"

int main() {
    int a, b;
    srand(time(NULL));
    printf("輸入一個整數: ");
    scanf("%d", &a);
    printf("整數 %d 的平方為 %d\n", a, fun2(a));
    b = fun3();
    printf("隨機數產生器得到的數為 %d\n", b);
    return 0;
}
