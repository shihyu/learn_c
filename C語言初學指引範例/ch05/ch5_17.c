/***************************
    檔名:ch5_17.c
    功能:break敘述的示範
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    short int Sum, n, i;
    printf("求1~N的總和,請輸入N值:");
    scanf("%d", &n);
    Sum = 0;

    for (i = 1; i <= n; i++) {
        if (Sum > 30000) {
            break;
        }

        Sum = Sum + i;
    }

    printf("1~%d的總和為%d\n", i - 1, Sum);
    /*  system("pause");  */
}
