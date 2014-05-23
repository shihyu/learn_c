/*
    使用strcpy函式將字串清空
*/

#include  <stdio.h>
#include  <string.h>

int main(void) {
    char  str[4] = "ABC";

    strcpy(str, "");

    printf("str = \"%s\"\n", str);

    system("PAUSE");
    return (0);
}
