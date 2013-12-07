/***************************
    檔名:ch5_03.c
    功能:if敘述的練習
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
    TotalPrice = OnePrice * Qty;

    if (Qty >= 10) {
        TotalPrice = TotalPrice * 0.9;
        printf("購買10張以上打九折\n");
    }

    printf("總價為%.0f元\n", TotalPrice);
    /*  system("pause");  */
}
