/***********************************
    檔名:ch5_04.c
    功能:條件運算式(判斷式)的成立
 ***********************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int x;
    char* str1;
    str1 = "答錯了";
    printf("請問1+1=");
    scanf("%d", &x);

    if (x = 2) {
        str1 = "答對了";
    }

    printf("%s\n", str1);
    /*  system("pause");  */
}
