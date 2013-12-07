/***************************
    檔名:ch4_04.c
    功能:printf()[width]參數
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int data1 = 1234;
    float data2 = 45.67;
    printf("        ==>123456789\n");  /* 對齊資料之用 */
    printf("           ---------\n");
    printf(" %%3d格式==>%3d\n", data1);
    printf(" %%6d格式==>%6d\n", data1);
    printf("%%03d格式==>%03d\n", data1);
    printf("%%06d格式==>%06d\n", data1);
    printf(" %%*d格式==>%*d\n", 5, data1);
    printf("==================================\n");
    printf("         ==>1234567890123456789\n");   /* 對齊資料之用 */
    printf("            -------------------\n");
    printf(" %%15f格式==>%15f\n", data2);
    printf("%%015f格式==>%015f\n", data2);
    printf("  %%*f格式==>%*f\n", 12, data2);
    /*  system("pause");  */
}
