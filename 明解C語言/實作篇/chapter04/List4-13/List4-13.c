/*
    「使用陣列的字串」與「使用指標的字串」
*/

#include  <stdio.h>

int main(void) {
    char  ary[] = "ABC";        /* 使用陣列的字串 */
    char*  ptr  = "abc";        /* 使用指標的字串 */

    printf("ary = %s\n", ary);
    printf("ptr = %s\n", ptr);

    system("PAUSE");
    return (0);
}
