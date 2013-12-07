/***************************
    檔名:ch6_08.c
    功能:字串反向
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    char string1[60], string2[60];
    int i, len;
    printf("請輸入字串:");
    scanf("%s", &string1);
    len = 0;

    while (string1[len] != '\0') {
        len++;
    }

    for (i = 0; i < len; i++) {
        string2[i] = string1[len - 1 - i];
    }

    string2[i] = '\0';
    printf("反向字串為:%s\n", string2);
    /*  system("pause");  */
}
