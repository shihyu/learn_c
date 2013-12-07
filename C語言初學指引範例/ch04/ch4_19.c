/***************************
    檔名:ch4_19.c
    功能:getche()函式
 ***************************/

#include <stdio.h>
#include <conio.h>  /* 必須引入conio.h */
#include <stdlib.h>

void main(void) {
    char ch1;
    printf("請輸入一個字元:");
    ch1 = getche();
    printf("\n");
    printf("您所輸入的是字元是%c", ch1);
    /*  system("pause");  */
}
