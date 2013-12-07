/*******************************
    檔名:ch10_01.c
    功能:typedef型態定義的練習
 *******************************/

#include <stdio.h>
#include <stdlib.h>

typedef float score;

void main(void) {
    score stu[3], total, avg;
    int i;
    total = 0;

    for (i = 1; i <= 3; i++) {
        printf("請輸入第%d位同學的成績:", i);
        scanf("%f", &stu[i - 1]);
        total = total + stu[i - 1];
    }

    avg = total / 3;
    printf("平均成績=%.3f\n", avg);
    /* system("pause"); */
}
