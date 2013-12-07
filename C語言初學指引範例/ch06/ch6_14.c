/****************************************
    檔名:ch6_14.c
    功能:strcpy(),strcat( )練習-組合字串
 ****************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void) {
    char string1[20], string2[20] = "股份有限公司", string3[20];
    char dest_string[60];
    printf("請輸入string1字串:");
    scanf("%s", &string1);
    printf("請輸入string3字串:");
    scanf("%s", &string3);
    strcpy(dest_string, string1);
    strcat(dest_string, string2);
    strcat(dest_string, string3);
    printf("dest_string:%s\n", dest_string);
    /*  system("pause");  */
}
