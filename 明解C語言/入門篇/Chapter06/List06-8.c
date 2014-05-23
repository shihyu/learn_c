/*
輸出直角三角形（直角在右下方）（函數版）
*/

#include  <stdio.h>
/*---連續輸出no個文字ch---*/
void put_nchar(int ch, int no) {
    while (no-- > 0) {
        putchar(ch);
    }
}

int main(void) {
    int  i, ln;

    printf("直角三角形共幾列：");
    scanf("%d", &ln);

    for (i = 1; i <= ln; i++) {
        put_nchar(' ', ln - i);
        put_nchar('*', i);
        putchar('\n');
    }

    return (0);
}
