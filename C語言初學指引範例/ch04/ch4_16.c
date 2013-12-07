/**************************
    檔名:ch4_16.c
    功能:gets函式
 **************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    char str1[] = "";
    char* str2 = "您所輸入的字串如下:";
    printf("請輸入一個字串:");
    gets(str1);      /*不建議使用gets*/
    puts(str2);
    puts(str1);
    /*  system("pause");  */
}
