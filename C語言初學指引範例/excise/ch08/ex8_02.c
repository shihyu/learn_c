#include <stdio.h>

void main(void) {
    char* str1 = "Hello C語言";
    char str2[100] = "";
    char* str3;
    printf("str1為:%s\n", str1);
    str3 = mystrcpy(str2, str1);
    printf("str2為:%s\n", str2);
    printf("str3為:%s\n", str3);
}
