

#include <stdio.h>
#include <stdlib.h>






int main(void) {
    char* s1[2] = {"Welcome", "shihyu"};
    printf("%p", (*(s1 + 0) + 0));
    system("pause");
    return 0;
}

char* inverse(char* dest, char* src) {
    int i, len;
    len = strlen(src);

    for (i = len - 1; i >= 0; i--) {
        *(dest + len - 1 - i) = *(src + i);
    }

    *(dest + len) = '\0';
    return dest;
}
