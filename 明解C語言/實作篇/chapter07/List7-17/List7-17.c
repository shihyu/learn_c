/*
    顯示結構的大小
*/

#include  <stdio.h>

int main(void) {
    struct test {
        char  c1;
        int   nx;
        char  c2;
    };

    printf("結構test整體的大小 = %u\n", (unsigned)sizeof(struct test));
    printf("結構test的成員的大小總合 = %u\n",
           (unsigned)(sizeof(char) + sizeof(int) + sizeof(char)));

    system("PAUSE");
    return (0);
}
