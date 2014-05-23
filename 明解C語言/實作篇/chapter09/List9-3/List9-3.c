/*
    進行輸入的確認(修正版1)
*/

#include  <ctype.h>
#include  <stdio.h>

/*--- 確認用函式 ---*/
int kakunin(void) {
    int  ch;

    while (isspace(ch = getchar())  &&  ch != EOF)
        ;

    return (ch);
}

int main(void) {
    int   ch;
    char  name[20];

    printf("請輸入名字 : ");
    scanf("%s", name);

    printf("這個名字正確嗎?(Y/N) : ");

    ch = kakunin();

    if (ch == 'Y'  ||  ch == 'y') {
        printf("%s先生(小姐)您好!\n", name);
        /* 【處理】 */
    }

    system("PAUSE");
    return (0);
}
