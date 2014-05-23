/*
  求1至5之和後再輸出（複合指定運算子）
*/

#include  <stdio.h>

int main(void) {
    int no = 1;
    int sum = 0;

    do {
        sum += no;                    /* no加到sum */
        no += 1;                      /* no加1 */
    } while (no <= 5);

    printf("從1加到5的總和之值為%d。\n", sum);

    return (0);
}
