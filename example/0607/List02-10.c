/*
   計算兩個整數的平均值之後再輸出成實數（cast）
*/

#include  <stdio.h>

int main(void) {
    float na, nb;

    puts("請輸入兩個整數:");
    printf("整數A：");
    scanf("%f", &na);
    printf("整數B：");
    scanf("%f", &nb);

    printf("其平均值是%f。\n", (na + nb) / 2);  // 不轉型會出錯 , 計算出來是整數, %f格式使用IEEE754 去解析會有問題

    // 下面四個強制轉型都可以
    printf("其平均值是%f。\n", (double)(na + nb) / 2);    /* cast */
    printf("其平均值是%f。\n", ((double)na + (double)nb) / 2);    /* cast */
    printf("其平均值是%f。\n", (((double)na + nb) / 2));    /* cast */
    printf("其平均值是%f。\n", ((na + (double)nb) / 2));    /* cast */
    printf("其平均值是%f。\n", ((na + nb) / 2.0));    /* cast */

    return (0);
}

