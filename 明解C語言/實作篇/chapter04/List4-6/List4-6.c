/*
    顯示字元常數的大小
*/

#include  <stdio.h>

int main(void) {
    printf("sizeof(char) = %u\n", (unsigned)sizeof(char));
    printf("sizeof(int)  = %u\n", (unsigned)sizeof(int));
    printf("sizeof('A')  = %u\n", (unsigned)sizeof('A'));

    system("PAUSE");
    return (0);
}
