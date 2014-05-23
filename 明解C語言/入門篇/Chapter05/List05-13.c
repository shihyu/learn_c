/*
  輸入成績（0～100），然後輸出其分布情形
*/
#include  <stdio.h>

#define NUMBER 80                        /* 上限人數 */

int main(void) {
    int i, j;
    int num;                /* 實際人數 */
    int tensu[NUMBER];      /* 學生成績 */
    int bunpu[11] = {0};    /* 分佈情形 */

    printf("請輸入人數：");

    do {
        scanf("%d", &num);

        if (num < 1  ||  num > NUMBER) {
            printf("\a必須【1以上%d以下】：", NUMBER);
        }
    } while (num < 1  ||  num > NUMBER);

    puts("請輸入成績：");

    for (i = 0; i < num; i++) {
        printf("%2d號：", i + 1);

        do {
            scanf("%d", &tensu[i]);

            if (tensu[i] < 0  ||  tensu[i] > 100) {
                printf("\a必須【0以上100以下】：");
            }
        } while (tensu[i] < 0  ||  tensu[i] > 100);

        bunpu[tensu[i] / 10]++;
    }

    puts("\n□ 長條圖 □");
    printf("    100:");

    for (j = 0; j < bunpu[10]; j++) {
        putchar('*');
    }

    putchar('\n');

    for (i = 9; i >= 0; i--) {
        printf("%3d-%3d：", i * 10, i * 10 + 9);

        for (j = 0; j < bunpu[i]; j++) {
            putchar('*');
        }

        putchar('\n');
    }

    return (0);
}
