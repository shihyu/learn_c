#include <stdio.h>

void main(void) {
    char* str1 = "Hello World!";
    printf("原始的字串為:%s\n", str1);
    ClearStr(&str1);
    printf("清除後字串為:%s\n", str1);
}
