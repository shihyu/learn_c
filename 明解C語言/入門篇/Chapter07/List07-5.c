/*
輸出unsigned型態的位元結構
*/

#include  <stdio.h>

/*---傳回整數x中的位元數---*/
int count_bits(unsigned x) {
    int  count = 0;

    while (x) {
        if (x & 1U) {
            count++;
        }

        x >>= 1;
    }

    return (count);
}

/*---傳回unsigned型態的位元數---*/
int int_bits(void) {
    return (count_bits(~0U));
}

/*---輸出unsigned型態的位元內容---*/
void print_bits(unsigned x) {
    int  i;

    for (i = int_bits() - 1; i >= 0; i--) {
        putchar(((x >> i) & 1U) ? '1' : '0');
    }
}

int main(void) {
    unsigned  nx;

    printf("請輸入一個非負的整數：");
    scanf("%u", &nx);

    print_bits(nx);
    putchar('\n');

    return (0);
}
