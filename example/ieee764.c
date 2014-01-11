#include <stdio.h>

int main(int argc, const char* argv[]) {
    long long a = 0xFFFFFFFF;
    printf("%p\n", &a);
    void* p = &a;
    unsigned long address = (unsigned long)p;
    printf("0x%lx\n", address);
    float f = -13.625; // 1 1000 0010 10110100000000000000000
    // c15a0000 = 1 1000 0010 10110100000000000000000
    printf("%08lx", *(unsigned long*)&f);
    return 0;
}
