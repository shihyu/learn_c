/*
    進行輸入確認(修正版?)
*/

#include  <stdio.h>

int main(void) {
    int   ch;
    char  name[20];

    printf("請輸入名字 : ");
    scanf("%s", name);

    printf("這個名字正確嗎?(Y/N) : ");

    fflush(stdin);          /* 將標準輸入串流的緩衝區更新 */

    ch = getchar();

    if (ch == 'Y'  ||  ch == 'y') {
        printf("%s先生(小姐)您好!\n", name);
        /* 【處理】 */
    }

    system("PAUSE");
    return (0);
}
