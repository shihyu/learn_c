/***************************
    檔名:ch4_03.c
    功能:printf()格式化符號
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int ch1 = 65;
    char ch2 = 'A';
    char* str1 = "Hello!";
    int data1 = 123456;
    int data2 = -45678;
    float f1, f2, sum;
    int count;
    f1 = 3.1415926;
    f2 = 1.41421;
    sum = f1 + f2;
    printf("%%c格式 %c\n", ch1);
    printf("%%c格式 %c\n", ch2);
    printf("%%s格式 %s\n", str1);
    printf("---------------------\n");
    printf("%%d格式 %d  %%i格式 %i\n", data1, data2);
    printf("%%o格式 %o\n", data1);
    printf("%%u格式 %u  %%u格式 %u\n", data1, data2);
    printf("%%x格式 %x  %%X格式 %X\n", data1, data1);
    printf("---------------------\n");
    printf("%%f格式 %f\n", f1);
    printf("%%e格式 %e  %%E格式 %E\n", f2, f2);
    printf("---------------------\n");
    printf("%%g格式 %g  %%G格式 %G\n", sum, sum);
    printf("%%p格式 %p\n", str1);
    printf("123%n\n", &count);
    printf("conut為%d\n", count);
    /*  system("pause");  */
}
