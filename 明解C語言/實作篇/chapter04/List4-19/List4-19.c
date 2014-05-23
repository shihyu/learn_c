/*
    代入空字元將字串清空
*/

#include  <stdio.h>


int main(void) {
    char  str[4] = "ABC";

    str[0] = '\0';

    printf("str = \"%s\"\n", str);

    system("PAUSE");
    return (0);
}
