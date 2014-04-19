#include <stdio.h>

void swap(int a, int b);

int main(int argc, char *argv[]) {
    int a, b;
    a = 50;
    b = 100;
    printf("main [+]a=%d, b=%d a address=%p, b address=%p\n", a, b, &a, &b);
    swap(a, b);
    printf("main [-]a=%d, b=%d a address=%p, b address=%p\n", a, b, &a, &b);
    return 0;
}

void swap(int a, int b) {
    printf("swap [+]a=%d, b=%d a address=%p, b address=%p\n", a, b, &a, &b);
    int temp = a;
    a = b;
    b = temp;
    printf("swap [-]a=%d, b=%d a address=%p, b address=%p\n", a, b, &a, &b);
}
