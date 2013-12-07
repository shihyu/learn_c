/***************************
    檔名:ch6_03.c
    功能:陣列元素初始化
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    float data1[10];
    float data2[10] = {0};
    int i;

    for (i = 0; i < 10; i++) {
        printf("data1[%d]=%.2f\n\t\t\t data2[%d]=%.2f\n", i, data1[i], i, data2[i]);
    }

    /*  system("pause");  */
}
