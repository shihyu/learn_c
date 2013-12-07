/***************************
    檔名:ch3_01.c
    功能:求圓面積
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int r = 3;
    const float pi = 3.1416;
    float area = pi * r * r;
    printf("半徑為%d", r);
    printf("的圓面積為%f\n", area);
    system("pause");
}
