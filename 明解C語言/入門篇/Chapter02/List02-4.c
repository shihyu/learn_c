/*
  將輸入的整數變號後再輸出
*/

#include <stdio.h>

int main(void) {
    int num;

    printf("請輸入整數：");
    scanf("%d", &num);

    printf("變號後之值是%d。\n", -num);  /*一元-運算子 */

    return (0);
}
