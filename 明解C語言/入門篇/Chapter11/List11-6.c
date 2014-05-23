/*
計算字串長度（指標版）
*/

#include  <stdio.h>

/*---傳回字串s長度---*/
size_t str_length(const char* s) {
    size_t   len = 0;

    while (*s++) {
        len++;
    }

    return (len);
}

int main(void) {
    char  st[100];

    printf("請輸入一個字串：");
    scanf("%s", st);

    printf("字串%s的長度為%u。\n", st, (unsigned)str_length(st));

    return (0);
}
