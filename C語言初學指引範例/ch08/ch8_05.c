/***************************
    檔名:ch8_05.c
    功能:指標變數的比較運算
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int a, b;
    int* p = &a, *q = &b;
    printf("指標p指向記憶體位址%p\n", p);
    printf("指標q指向記憶體位址%p\n", q);

    if (p > q) {
        printf("變數a的記憶體位址高於變數b的記憶體位址\n");
    } else {
        printf("變數b的記憶體位址高於變數a的記憶體位址\n");
    }

    /*  system("pause");  */
}
