/*
    顯示字串字面值的大小
*/

#include  <stdio.h>

int main(void) {
    printf("sizeof(\"ABC\") = %u\n", (unsigned)sizeof("ABC"));
    printf("sizeof(\"ABC\\0DEF\") = %u\n", (unsigned)sizeof("ABC\0DEF"));

    system("PAUSE");
    return (0);
}
