/*
    進行輸入的確認(有問題: getchar函式的呼叫被忽略了?)
*/

#include  <stdio.h>

int main(void) {
    int   ch;
    char  name[20];

    printf("請輸入名字 : ");
    scanf("%s", name);

    printf("這個名字正確嗎?(Y/N) : ");

    ch = getchar();                     /* 這個函式呼叫將被忽略? */

    if (ch == 'Y'  ||  ch == 'y') {
        printf("%s%s先生(小姐)您好!\n", name);        /* 不被執行 */
        /* 【處理】 */                              /* 不被執行 */
    }

    return (0);
}
