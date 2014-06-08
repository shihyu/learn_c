#include <stdio.h>

void show_char(char* s) {
    
    while (*s != '\0') {
        printf("%c", *s++);
    }
}

int main(void) {
    char* name = "1485";

#if 0
    //printf("%s\n", name);
    //printf("%d\n", *(name + 0));
    //printf("%c\n", *(name + 0));
    printf("%s\n", name);
    printf("%d\n", *name+1);
    printf("%d\n", (*name) + 1);
    printf("%d\n", *(name + 1));
    printf("%d\n", *(name + 2));
    printf("%c\n", *(name + 2));
#endif

    printf("%c\n", 48);
    printf("%d\n", '0');
    printf("%s\n", name);
    show_char(name);

    return (0);
}
