#include <stdio.h>

void main(void) {
    char* str1 = "My dear friend";
    char* str2;
    printf("str1為:%s\n", str1);
    str2 = DeleteEmpty(str1);
    printf("str2為:%s\n", str2);
}
