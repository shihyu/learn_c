/*
  製作直角三角形（直角在右下方）
*/
#include  <stdio.h>

int main(void) {
    int  i, j, ln;

    printf("直角三角形共幾列：");
    scanf("%d", &ln);

    for (i = 1; i <= ln; i++) {
        for (j = 1; j <= ln - i; j++) {
            putchar(' ');
        }

        for (j = 1; j <= i; j++) {
            putchar('*');
        }

        putchar('\n');
    }

    return (0);
}
