/***************************
    檔名:ch7_01.c
    功能:呼叫函式
 ***************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void) {
    char string1[60] = "Welcome", string2[60];
    int len;
    strcpy(string2, string1);
    printf("string2=%s\n", string2);
    len = strlen(string2);
    printf("字串長度為%d\n", len);
    /*  system("pause");  */
}
