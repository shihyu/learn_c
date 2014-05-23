/*
    讀入整數並顯示總合(空敘述的使用範例:做為標籤文的主體)
*/

#include  <stdio.h>

/*--- 讀入no個整數並顯示總計值 */
void sumup(int no) {
    int  sum = 0;

    printf("請輸入%d個整數。\n", no);
    puts("輸入999就會中斷處理。");

    while (no--) {
        int  x;
        scanf("%d", &x);

        if (x == 999) {
            goto xyz;    /* 中斷 */
        }

        sum += x;
    }

    printf("總計為%d。\n", sum);
xyz:
    ;                       /* 空敘述 */
}

int main(void) {
    sumup(5);

    system("PAUSE");
    return (0);
}
