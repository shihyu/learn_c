/***************************
    檔名:ch7_26.c
    功能:使用遞迴求費氏數列
 ***************************/

#include <stdio.h>
#include <stdlib.h>

int Fib(int n);

/**************Fib()***************/
int Fib(int n) {
    if ((n == 1) || (n == 0)) {
        return n;
    } else {
        return Fib(n - 1) + Fib(n - 2);
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
