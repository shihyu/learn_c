/***************************
    檔名:ch6_01.c
    功能:計算陣列大小
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    char name[5];
    int score[6];
    double rate[6];
    printf("name[5]共使用%dbytes\n", sizeof(name));
    printf("score[6]共使用%dbytes\n", sizeof(score));
    printf("rate[6]共使用%dbytes\n", sizeof(rate));
    /*  system("pause");  */
}

