/***************************
    檔名:ch3_03.c
    功能:複雜的算數運算
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    float  answer;
    float  a = 2.1, b = 3.5, c = 4;
    printf("a=%f     ", a);
    printf("b=%f     ", b);
    printf("c=%f\n", c);
    answer = b * b - 4 * a * c;
    printf("b^2-4ac=%f\n", answer);
    system("pause");
}
