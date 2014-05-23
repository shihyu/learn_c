/*
將同名的函數與巨集做區分的程式例
*/
#include <stdio.h>
/*---巨集版---*/
#define max(a, b) ((a) > (b) ? (a) : (b))
/*---函數版---*/
int (max)(int a, int b) {
    puts("函數版max被呼叫了。");
    return (a > b ? a : b);
}

int main(void) {
    int x, y;
    printf("x的值為：");
    scanf("%d", &x);
    printf("y的值為：");
    scanf("%d", &y);
    printf("max(x, y) = %d\n\n", max(x, y)); /*呼叫巨集版*/
    printf("(max)(x, y) = %d\n", (max)(x, y)); /*呼叫函數版*/
    system("PAUSE");
    return (0);
}
