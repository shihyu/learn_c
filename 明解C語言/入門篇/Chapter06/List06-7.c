/*
輸出直角三角形（直角在左下方）（函數版）
*/

#include  <stdio.h>

/*---連續輸出no個 * 記號---*/
void put_stars(int no) {
    while (no-- > 0) {
        putchar('*');
    }
}

int main(void) {
    int  i, ln;

    printf("直角三角形共幾列：");
    scanf("%d", &ln);

    for (i = 1; i <= ln; i++) {
        put_stars(i);
        putchar('\n');
    }

    return (0);
}
