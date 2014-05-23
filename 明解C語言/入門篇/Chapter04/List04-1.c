/*
  輸入的整數是奇數或偶數？（可重覆處理）
*/

#include  <stdio.h>

int main(void) {
    int  cont;              /* 是否繼續處理？ */

    do {
        int no;

        printf("請輸入一個整數：");
        scanf("%d", &no);

        if (no % 2) {
            puts("此數字是奇數。");
        } else {
            puts("此數字是偶數。");
        }

        printf("是否繼續?【Yes...0/No...9】：");
        scanf("%d", &cont);
    } while (cont == 0);

    return (0);
}

