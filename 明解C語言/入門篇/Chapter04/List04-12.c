/*
  從0開始計數到某正整數之值（for敘述）
*/

#include  <stdio.h>

int main(void) {
    int i, no;

    printf("請輸入正整數：");
    scanf("%d", &no);

    for (i = 0; i <= no; i++) {
        printf("%d ", i);
    }

    putchar('\n');

    return (0);
}
