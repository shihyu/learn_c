/*
  計算兩個整數之商與餘數再輸出
*/

#include <stdio.h>

int main(void) {
    int na, nb;

    puts("請輸入整數：");
    printf("整數A：");
    scanf("%d", &na);
    printf("整數B：");
    scanf("%d", &nb);

    printf("A除以B的商是%d、餘數是%d。\n", na / nb, na % nb);

    return (0);
}
