/*
    顯示結構成員的位移量
*/

#include  <stdio.h>
#include  <stddef.h>

struct test {
    char  c1;
    int   nx;
    char  c2;
};

int main(void) {
    printf("c1的位移量 = %u\n", (unsigned)offsetof(struct test, c1));
    printf("nx的位移量 = %u\n", (unsigned)offsetof(struct test, nx));
    printf("c2的位移量 = %u\n", (unsigned)offsetof(struct test, c2));

    system("PAUSE");
    return (0);
}
