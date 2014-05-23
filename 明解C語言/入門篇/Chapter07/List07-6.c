/*
块 unsigned 篈呸胯縩呸胯㎝逼┦呸胯㎝1干计
*/

#include  <stdio.h>

/*---肚俱计xいじ---*/
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

/*---肚unsigned篈じ计---*/
int int_bits(void) {
    return (count_bits(~0U));
}

/*---块unsigned篈じず甧---*/
void print_bits(unsigned x) {
    int     i;

    for (i = int_bits() - 1; i >= 0; i--) {
        putchar(((x >> i) & 1U) ? '1' : '0');
    }
}

int main(void) {
    unsigned  na, nb;

    puts("叫块ㄢ獶璽计俱计");
    printf("俱计A");
    scanf("%u", &na);
    printf("俱计B");
    scanf("%u", &nb);

    printf("\nA   = ");
    print_bits(na);
    printf("\nB   = ");
    print_bits(nb);
    printf("\nA&B = ");
    print_bits(na & nb);     /* 呸胯縩 */
    printf("\nA|B = ");
    print_bits(na | nb);     /* 呸胯㎝ */
    printf("\nA^B = ");
    print_bits(na ^ nb);     /* 逼┦呸胯㎝ */
    printf("\n~A  = ");
    print_bits(~na);         /* 1 干计 */
    printf("\n~B丂= ");
    print_bits(~nb);         /* 1 干计 */
    putchar('\n');

    return (0);
}
