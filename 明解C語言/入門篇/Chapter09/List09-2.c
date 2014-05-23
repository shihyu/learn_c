/*
存放字串的陣列
*/

#include  <stdio.h>

int main(void) {
    char  str[4];   /*存放字串的陣列*/
    str[0] = 'A';   /* 指定 */
    str[1] = 'B';   /* 指定 */
    str[2] = 'C';   /* 指定 */
    str[3] = '\0';  /* 指定 */

    printf("字串str為%s。\n", str); /* 顯示出來 */

    return (0);
}
