/***************************************************
    檔名:ch6_13.c
    功能:strcpy(),strncpy()練習-複製字串及部分字串
 ***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void) {
    char src_string[] = "程式設計C語言";
    char dest_string[60], dest_substring[60];
    strcpy(dest_string, src_string);
    strncpy(dest_substring, src_string, 8);
    printf("複製的完整字串為:%s\n", dest_string);
    printf("複製的部分字串為:%s\n", dest_substring);
    /*  system("pause");  */
}
