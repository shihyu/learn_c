/*
    在字串中填滿空字元
*/

#include  <stdio.h>
#include  <string.h>

int main(void) {
    int   i;
    char  s[10] = "ABCDEFGHI";

    memset(s, '\0', sizeof(s));     /* 將陣列s的全元素設為0 */

    for (i = 0; i < sizeof(s); i++) {
        printf("s[%d] = %d\n", i, s[i]);
    }

    system("PAUSE");
    return (0);
}
