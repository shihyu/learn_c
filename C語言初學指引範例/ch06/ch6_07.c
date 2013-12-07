/***************************
    檔名:ch6_07.c
    功能:計算字串長度
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    char string[] = "I love Kitty";
    int i;
    i = 0;

    while (string[i] != '\0') {
        i++;
    }

    printf("字串%s的長度為%d\n", string, i);
    /*  system("pause");  */
}
