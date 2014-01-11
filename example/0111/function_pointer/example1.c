#include <stdio.h>

void func1(void) {
    printf("func1\n");
}

void func2(void) {
    printf("func2\n");
}

int main(void) {
    void (*f)(void);
    f = func1; // f指向func1
    (*f)();  // 呼叫f, 也就等於呼叫func1
    f = func2; // f指向func2
    f();     // 呼叫f, 也就等於呼叫func2, 直接寫f()也行.
    return 0;
}
