#include <stdio.h>
#include <stdlib.h>

int add(int w) {
    int x = 0;
    x = x + w;
    return x;
}

void main(void) {
    int a = 0;
    int i;

    for (i = 1; i <= 5; i++) {
        a = add(i);
    }

    printf("a=%d\n", a);
}
