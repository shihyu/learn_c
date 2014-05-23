/*
將字串 "12345" 格式化再輸出
*/

#include  <stdio.h>

int main(void) {
    char  str[] = "12345";

    printf("%s\n",     str);    /* 照本宣科 */
    printf("%3s\n",   str);     /* 最少三位數 */
    printf("%.3s\n",  str);     /* 最多三位數 */
    printf("%8s\n",   str);     /* 靠右對齊 */
    printf("%-8s\n",  str);     /* 靠左對齊 */

    return (0);
}
