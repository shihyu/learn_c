/*
    進行輸入確認(修正版2)
*/

#include  <ctype.h>
#include  <stdio.h>

/*--- 讀入1個非空白類文字 ---*/
int getnschar(void) {
    int  ch;

    while (isspace(ch = getchar())  &&  ch != EOF)
        ;

    return (ch);
}

/*--- 確認(只讀入'Y'，'y'，'N'，'n') ---*/
int kakunin(void) {
    int  ch;

    do {
        ch = getnschar();

        if (ch == 'Y'  ||  ch == 'y') {
            return (1);
        }

        if (ch == 'N'  ||  ch == 'n') {
            return (0);
        }
    } while (ch != EOF);

    return (EOF);
}

int main(void) {
    int   ch;
    char  name[20];

    printf("請輸入名字 : ");
    scanf("%s", name);

    printf("這個名字正確嗎?(Y/N) : ");

    ch = kakunin();

    if (ch == 1) {
        printf("%s先生(小姐)您好!\n", name);
        /* 【處理】 */
    }

    system("PAUSE");
    return (0);
}
