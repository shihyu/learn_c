/***************************
    檔名:ch5_16.c
    功能:continue敘述的示範
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int Sum = 0, i, j;

    for (i = 1; i <= 10; i++) {
        if ((i % 2) == 1) {
            continue;
        }

        Sum = Sum + i;
    }

    printf("2+4+6+8+10=%d\n", Sum);
    /*  system("pause");  */
}
