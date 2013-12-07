/***************************
    檔名:ch6_10.c
    功能:標準輸入裝置
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    char fgets_string[100];
    char scanf_string[100];
    printf("請輸入scanf字串:");
    scanf("%s", &scanf_string);
    printf("請輸入fgets字串:");
    fgets(fgets_string, 100, stdin);
    printf("您輸入的scanf字串是%s\n", scanf_string);
    printf("您輸入的fgets字串是%s", fgets_string);
    /*  system("pause");  */
}
