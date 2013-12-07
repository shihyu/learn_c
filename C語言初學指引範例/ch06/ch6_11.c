/***************************
    檔名:ch6_11.c
    功能:puts()函式練習
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    char string1[100], string2[100];
    printf("請輸入string1字串:");
    fgets(string1, 100, stdin);
    printf("請輸入string2字串:");
    scanf("%s", &string2);
    printf("string1字串是");
    puts(string1);
    printf("string2字串是");
    puts(string2);
    /*  system("pause");  */
}
