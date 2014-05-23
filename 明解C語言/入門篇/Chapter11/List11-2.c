/*
陣列字串與指標字串的共同點
*/

#include  <stdio.h>

int main(void) {
    int    i;
    char   str[] = "ABC";
    char*  ptr   = "123";

    for (i = 0; str[i]; i++) {
        putchar(str[i]);    /* str[i]是前端起算的後I個元素 */
    }

    putchar('\n');

    for (i = 0; ptr[i]; i++) {
        putchar(ptr[i]);    /* ptr[i]是前端起算的後I個元素 */
    }

    putchar('\n');

    printf("str = \"%s\"\n", str);      /* str是指向前端字元的指標 */
    printf("ptr = \"%s\"\n", ptr);      /* ptr 是指向前端字元的指標 */

    return (0);
}
