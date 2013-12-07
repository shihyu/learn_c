/***************************
    檔名:ch7_27.c
    功能:使用迴圈求費氏數列
 ***************************/

#include <stdio.h>
#include <stdlib.h>

int Fib(int n);

/**************Fib()***************/
int Fib(int n) {
    int n1 = 0, n2 = 0, sum = 1, i;

    if ((n == 1) || (n == 0)) {
        return n;
    } else {
        for (i = 2; i <= n; i++) {
            n1 = sum;
            sum = sum + n2;
            n2 = n1;
        }

        return sum;
    }
}

/**************main()**************/
void main(void) {
    int i;
    printf("費氏數列如下:");

    for (i = 0; i <= 25; i++) {
        if (i % 8 == 0) {
            printf("\n");
        }

        printf("%d\t", Fib(i));
    }

    printf("......\n");
    /*  system("pause");  */
}
