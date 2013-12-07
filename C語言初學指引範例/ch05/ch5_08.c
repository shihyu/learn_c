/***************************
    檔名:ch5_08.c
    功能:條件運算式的練習
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    long Credit;    /*  信用額度 */
    int Status;     /*  繳款狀態 */
    float Year;     /*  持卡年份 */
    printf("請輸入信用額度:");
    scanf("%d", &Credit);
    printf("繳款是否正常(1:正常,0:不正常):");
    scanf("%d", &Status);

    if (!(Status)) {
        printf("預借現金金額為0元\n");
    } else {
        printf("請輸入持卡年份:");
        scanf("%f", &Year);
    }

    if ((Status) && (Year >= 0.5) && (Year < 1)) {
        printf("預借現金金額為%.0f元\n", Credit * 0.5);
    }

    if ((Status) && (Year >= 1)) {
        printf("預借現金金額為%d元\n", Credit);
    }

    if ((Status) && (Year < 0.5)) {
        printf("預借現金金額為0元\n");
    }

    /*  system("pause");  */
}
