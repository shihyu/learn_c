#include <stdio.h>

int main() {
    int i = 0xc15a0000;  // 1 1000 0010 10110100000000000000000
    float f = -13.625;  // 1 1000 0010 10110100000000000000000
    int _i = -1051066368;  // 1 1000 0010 10110100000000000000000

    // c15a0000 = 1 1000 0010 10110100000000000000000   IEEE 754
    printf("0x%08X\n", *(unsigned int*)&f);
    printf("0x%08X\n", *(unsigned int*)&i);
    printf("0x%08X\n\n", *(unsigned int*)&_i);

    printf("f=%f\n",f);
    // printf("f=%d\n",f);
    printf("i =%f\n",i);
<<<<<<< HEAD
    printf("_i=%f\n",_i);

=======
    printf("_i=%f\n\n",_i);

    printf("%d\n",*(int*)&f);
>>>>>>> 0b572d343eb8c9f00561e71d1113889649dfc9e4

    return 0;
}
