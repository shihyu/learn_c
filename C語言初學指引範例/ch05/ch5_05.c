/***************************
    檔名:ch5_05.c
    功能:if-else敘述的練習
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int OnePrice, Qty;
    float TotalPrice;
    OnePrice = 200;
    printf("每張入場卷價格為%d元\n", OnePrice);
    printf("請輸入您要購買的張數:");
    scanf("%d", &Qty);
    printf("==========================\n");

    if (Qty >= 10) {
        TotalPrice = OnePrice * Qty * 0.9;
        printf("購買10張以上打九折\n");
    } else {
        TotalPrice = OnePrice * Qty;
        printf("您為購買10張以上的入場券,恕不打折\n");
    }

    printf("總價為%.0f元\n", TotalPrice);
    /*  system("pause");  */
}
