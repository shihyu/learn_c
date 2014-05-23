/*
  連續輸出相當於某非負數整數之值個數的＊記號（可多次執行）
*/
#include  <stdio.h>

int main(void) {
    int  cont;

    do {
        int   num, i;

        do {
            printf("請輸入非負數的整數：");
            scanf("%d", &num);

            if (num < 0) {
                puts("\a請勿輸入負整數");
            }
        } while (num < 0);

        /* num > 0 才予以處理*/
        for (i = 1; i <= num; i++) {
            putchar('*');
        }

        putchar('\n');

        printf("是否繼續？【Yes...0/No...9】：");
        scanf("%d", &cont);
    } while (!cont);

    return (0);
}

