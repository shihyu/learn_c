#include <stdio.h>

int main() {
    int i = 0xc15a0000; 
    float f = -13.625; // 1 1000 0010 10110100000000000000000
    int _i = -1051066368;

    // c15a0000 = 1 1000 0010 10110100000000000000000   IEEE 754
    printf("0x%08X\n", *(unsigned int*)&f);
    printf("0x%08X\n", *(unsigned int*)&i);
    printf("0x%08X\n", *(unsigned int*)&_i);

    printf("f=%f\n",f);
    printf("i =%f\n",i);
    printf("_i=%f\n",i);

    return 0;
}
