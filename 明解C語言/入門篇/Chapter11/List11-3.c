/*
字串的指定（？）
*/

#include  <stdio.h>

int main(void) {
    char   str[] = "ABC";
    char*  ptr   = "123";

    str = "DEF";        /* 錯誤：無法指定初始化子 */
    ptr = "456";        /* 正確：指定其他字串字面值 */

    printf("str = \"%s\"\n", str);
    printf("ptr = \"%s\"\n", ptr);

    return (0);
}
