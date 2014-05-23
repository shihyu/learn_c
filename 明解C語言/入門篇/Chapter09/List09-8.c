/*
計算字串長度
*/

#include  <stdio.h>

/*---傳回字串str長度---*/
unsigned str_length(const char str[]) {
    unsigned  len = 0;

    while (str[len]) {
        len++;
    }

    return (len);
}

int main(void) {
    char  st[100];

    printf("請輸入字串：");
    scanf("%s", st);

    printf("字串%s的長度為%u。\n", st, str_length(st));

    return (0);
}
