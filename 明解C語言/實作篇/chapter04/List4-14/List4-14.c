/*
    「使用陣列的字串」與「使用指標的字串」的陣列
*/

#include  <stdio.h>

int main(void) {
    int   i;
    char  a[][6] = {"S5000", "V8", "W140"};
    char*  p[]   = {"12345", "AB", "abcd"};

    for (i = 0; i < 3; i++) {
        printf("a[%d] = %s\n", i, a[i]);
    }

    for (i = 0; i < 3; i++) {
        printf("p[%d] = %s\n", i, p[i]);
    }

    system("PAUSE");
    return (0);
}
