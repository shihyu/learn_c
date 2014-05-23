/*
  求1至5之和後再輸出
*/

#include  <stdio.h>

int main(void) {
    int no = 1;
    int sum = 0;

    do {
        sum = sum + no;
        no = no + 1;
    } while (no <= 5);

    printf("從1加到5的總和之值為%d。\n", sum);

    return (0);
}
