/*
輸出unsigned型態左／右移後之值
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
    unsigned  nx, no;

    printf("請輸入一個非負整數：");
    scanf("%u", &nx);
    printf("欲移位幾位元：");
    scanf("%u", &no);

    printf("\n整數      = ");
    print_bits(nx);
    printf("\n左移後之值= ");
    print_bits(nx << no);
    printf("\n右移後之值= ");
    print_bits(nx >> no);
    putchar('\n');

    return (0);
}
