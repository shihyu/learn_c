/*
    將字串字面值評價後的值顯示
*/

#include  <stdio.h>

int main(void) {
    char*  ptr = "ABCD";            /*以指向前頭字元的指標來做初始化*/

    printf("ptr  = %s\n", ptr);     /* 被ptr指著前頭字元的字串 */
    printf("ptr  = %p\n", ptr);     /* ptr本身(位址) */
    printf("*ptr = %c\n", *ptr);    /* ptr所指的字元 */

    system("PAUSE");
    return (0);
}
