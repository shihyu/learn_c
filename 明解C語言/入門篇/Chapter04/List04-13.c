/*
  以＊的記號來顯示某正整數之位數（for敘述）
*/
#include  <stdio.h>

int main(void) {
    int i, no;

    printf("請輸入正整數：");
    scanf("%d", &no);

    for (i = 1; i <= no; i++) {
        putchar('*');
    }

    putchar('\n');

    return (0);
}
