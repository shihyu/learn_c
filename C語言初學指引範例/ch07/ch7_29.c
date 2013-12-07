/***************************
    檔名:ch7_29.c
    功能:巨集取代字串
 ***************************/

#include <stdio.h>
#include <stdlib.h>

#define WelcomeString "歡迎使用本程式"
#define Running "程式執行中"
#define loop3   for(i=1;i<=3;i++){\
                   printf(Running);\
                   printf("\n");\
                }

void main(void) {
    int i;
    printf(WelcomeString);
    printf("\n");
    loop3
    /*  system("pause");  */
}
