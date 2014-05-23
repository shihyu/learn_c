/*
求階乘
*/

#include  <stdio.h>

/*---傳回階乘值---*/
int factorial(int n) {
    if (n > 0) {
        return (n * factorial(n - 1));
    } else {
        return (1);
    }
}

int main(void) {
    int  num;

    printf("請輸入一個整數：");
    scanf("%d", &num);

    printf("該數的階乘為%d。\n", factorial(num));

    return (0);
}
