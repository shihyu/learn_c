/*
陣列字串與指標字串
*/

#include  <stdio.h>

int main(void) {
    char   str[] = "ABC";       /* 陣列字串 */
    char*  ptr   = "123";       /* 指標字串 */

    printf("str = \"%s\"\n", str);
    printf("ptr = \"%s\"\n", ptr);

    return (0);
}
