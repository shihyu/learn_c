/***************************
    檔名:ch6_04.c
    功能:陣列與排序
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int x[6] = {25, 10, 39, 40, 33, 12};
    int spec = 11;
    int k, times, i, temp;
    k = 6 - 1;

    while (k != 0) {
        times = 0;

        for (i = 0; i <= k - 1; i++) {
            if (x[i] > x[i + 1]) {
                temp = x[i];
                x[i] = x[i + 1];
                x[i + 1] = temp; /* x[i]與x[i+1]互換 */
                times = i;
            }
        }

        k = times;
    }

    for (i = 0; i < 6; i++) {
        printf("%d\t", x[i]);
    }

    printf("\n特別號\t%d\n", spec);
    /*  system("pause");  */
}
