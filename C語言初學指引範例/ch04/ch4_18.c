/**************************
    檔名:ch4_18.c
    功能:fputs函式
 **************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    char* str1 = "Hello";
    char* str2 = "Welcome!";
    fputs(str1, stdout);
    fputs("\n", stdout);
    fputs(str2, stdout);
    /*  system("pause");  */
}
