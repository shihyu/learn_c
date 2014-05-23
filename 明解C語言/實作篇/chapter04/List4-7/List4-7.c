/*
    字串的初始化與顯示(確認字串的結尾等於第一個遇到的空字元)
*/

#include  <stdio.h>

int main(void) {
    char  a[4] = {'S', 'X', '\0', '2'};     /* 'S', 'X', '\0', '2' */
    char  b[4] = "ABC";         /* 'A', 'B', 'C', '\0' */

    printf("a = %s\n", a);
    printf("b = %s\n", b);

    system("PAUSE");
    return (0);
}
