#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int oper(int a, int b, int (*f)(int a, int b)) {
    return f(a, b);
}

int main(void) {
    printf("add(1,2)=%d\n", oper(1, 2, add));
    printf("sub(1,2)=%d\n", oper(1, 2, sub));
    return 0;
}
