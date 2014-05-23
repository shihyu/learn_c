/*
顯示所讀取的整數數值要求確認
*/

#include <stdio.h>

int main(void) {
    int no;

    printf("請輸入整數：");
    scanf("%d", &no);

    printf("您輸入的整數為%d。\n", no);

    return 0;
}
