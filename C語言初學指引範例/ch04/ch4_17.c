/**************************
    檔名:ch4_17.c
    功能:fgets函式
 **************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    char str1[] = "";
    char* str2 = "您所輸入的字串如上";
    printf("請輸入一個字串:");
    fgets(str1, 80, stdin);    /*使用fgets取代gets*/
    printf("%s", str1);
    printf("%s", str2);
    /*  system("pause");  */
}
