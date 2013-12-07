/***************************
    檔名:ch4_05.c
    功能:printf()[.prec]參數
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int data1 = 1234;
    float data2 = 45.6789;
    double data3 = 78.900000;
    char* str1 = "Hello!";
    printf("   %%d格式==>%d\n", data1);
    printf("   %%f格式==>%f\n", data2);
    printf("   %%g格式==>%g\n", data3);
    printf("   %%s格式==>%s\n", str1);
    printf("==================================\n");
    printf("        ==>1234567890123456789\n");  /*對齊資料之用*/
    printf("           -------------------\n");
    printf("%%.0d格式==>%.0d\n", data1);
    printf("%%.0f格式==>%.0f\n", data2);
    printf("==================================\n");
    printf("        ==>1234567890123456789\n");  /*對齊資料之用*/
    printf("           -------------------\n");
    printf("%%.3s格式==>%.3s\n", str1);
    printf("%%.1f格式==>%.1f\n", data2);
    printf("%%.5f格式==>%.5f\n", data2);
    printf("%%.1g格式==>%.1g\n", data3);
    printf("%%.5g格式==>%.5g\n", data3);
    printf("==================================\n");
    printf("        ==>1234567890123456789\n");  /*對齊資料之用*/
    printf("           -------------------\n");
    printf("%%.*f格式==>%.*f\n", 3, data2);
    /*  system("pause");  */
}
