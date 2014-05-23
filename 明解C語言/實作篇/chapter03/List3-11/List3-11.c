/*
    顯示字串
*/

#include  <stdio.h>

/*--- 將字串一個字一個字顯示 ---*/
void putstr(const char* s) {
    int  i;

    for (i = 0; s[i] != '\0'; i++) {
        putchar(s[i]);
    }
}

int main(void) {
    char  str[100];

    printf("請輸入字串 : ");
    scanf("%s", str);

    putstr(str);
    putchar('\n');

    system("PAUSE");
    return (0);
}
