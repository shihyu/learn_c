/*
  製作矩形
*/
#include  <stdio.h>

int main(void) {
    int  i, j;
    int  width, height;

    puts("開始製作矩形");
    printf("寬：");
    scanf("%d", &width);
    printf("高：");
    scanf("%d", &height);

    for (i = 1; i <= height; i++) {
        for (j = 1; j <= width; j++) {
            putchar('*');
        }

        putchar('\n');
    }

    return (0);
}
