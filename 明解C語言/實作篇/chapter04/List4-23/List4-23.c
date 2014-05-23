/*
    將字串用空字元填滿(錯誤版)
*/

#include  <stdio.h>
#include  <string.h>

/*--- 在字串str中填滿空字元(錯誤) ---*/
void clear_string(char* str) {
    memset(str, '\0', sizeof(str));
}

int main(void) {
    int   i;
    char  s[10] = "ABCDEFGHI";

    clear_string(s);

    for (i = 0; i < sizeof(s); i++) {
        printf("s[%d] = %d\n", i, s[i]);
    }

    system("PAUSE");
    return (0);
}
