/***************************
    檔名:ch7_28.c
    功能:巨集取代常數
 ***************************/

#include <stdio.h>
#include <stdlib.h>

#define PI 3.1416
#define R 3

void main(void) {
    float area, length;
    area = PI * R * R;
    length = 2 * PI * R;
    printf("半徑為3的圓面積為%.4f\n", area);
    printf("半徑為3的圓周長為%.4f\n", length);
    /*  system("pause");  */
}
