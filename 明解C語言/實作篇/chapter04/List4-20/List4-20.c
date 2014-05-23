/*
    字串的操作
*/

#include  <stdio.h>
#include  <string.h>

int main(void) {
    char  str[8] = "";

    strcpy(str, "ABCD");
    printf("str = %s\n", str);
    strcpy(str, "");
    printf("str = %s\n", str);
    str[0] = '1';
    printf("str = %s\n", str);
    str[1] = '2';
    printf("str = %s\n", str);

    system("PAUSE");
    return (0);
}
