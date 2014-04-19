#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

void aaa1(void) {
    printf("func1\n");
}

void func2(void) {
    printf("func2\n");
}

int main(void) {
    void (*f)(void) = aaa1;
    int (*p)(int, int) = add;

    printf("%d\n", p(10, 30));
    printf("%d\n", add(10, 30));

    // f = func1; // f指向func1
    (*f)();  // 呼叫f, 也就等於呼叫func1
    // func1();

    f = func2; // f指向func2
    f();     // 呼叫f, 也就等於呼叫func2, 直接寫f()也行.

    return 0;
}
