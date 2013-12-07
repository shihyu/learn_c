/***************************
    檔名:ch6_02.c
    功能:陣列元素的存取
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    float Temper[12], sum = 0, average;
    int i;

    for (i = 0; i < 12; i++) {
        printf("%d月的平均溫度:", i + 1);
        scanf("%f", &Temper[i]);
        sum = sum + Temper[i];
    }

    average = sum / 12;
    printf("=========================\n");
    printf("年度平均溫度:%f\n", average);
    /*  system("pause");  */
}
