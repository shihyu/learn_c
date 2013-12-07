/*******************************
    檔名:ch6_12.c
    功能:strlen()練習-字串反向
 *******************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void) {
    char string1[60], string2[60];
    int i, len;
    printf("請輸入字串:");
    scanf("%s", &string1);
    len = strlen(string1);
    printf("字串長度為%d\n", len);

    for (i = 0; i < len; i++) {
        string2[i] = string1[len - 1 - i];
    }

    string2[i] = '\0';
    printf("反向字串為:%s\n", string2);
    /*  system("pause");  */
}
