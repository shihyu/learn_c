/***************************
    檔名:ch4_07.c
    功能:[flags]參數
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int var1 = 5555, var2 = 6666, var3 = 7777;
    float data1 = 123.4, data2 = -45.678, data3 = 0.92000;
    printf("%-10f<==data1\n", data1);
    printf("%-10f<==data2\n", data2);
    printf("%-10f<==data3\n", data3);
    printf("---------------------\n");
    printf("data1==>%+.5f\n", data1);
    printf("data2==>%+.5f\n", data2);
    printf("data3==>%+.5f\n", data3);
    printf("---------------------\n");
    printf("data1==>% .5f\n", data1);
    printf("data2==>% .5f\n", data2);
    printf("data3==>% .5f\n", data3);
    printf("---------------------\n");
    printf("data1==>%#g\n", data1);
    printf("data2==>%#g\n", data2);
    printf("data3==>%#g\n", data3);
    printf("---------------------\n");
    printf("var1==>%#x\n", var1);
    printf("var2==>%#x\n", var2);
    printf("var3==>%#x\n", var3);
    printf("---------------------\n");
    printf("%-#10g<==data1\n", data1);
    printf("%-#10g<==data2\n", data2);
    printf("%-#10g<==data3\n", data3);
    /*  system("pause");  */
}
