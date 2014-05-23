/*
    確認使用register宣告的物件的位址無法取得
*/

#include  <stdio.h>

int main(void) {
    register int  x;

    printf("x的位址 = %p\n", &x);    /*錯誤*/

    return (0);
}
