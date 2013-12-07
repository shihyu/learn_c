/*******************************
    檔名:ch9_09.c
    功能:register變數
 *******************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    register int i, m;
    m = 0;

    for (i = 1; i < 10000; i++) {
        m = m + i;
    }

    printf("m=%d\n", m);
    /*  system("pause");  */
}
