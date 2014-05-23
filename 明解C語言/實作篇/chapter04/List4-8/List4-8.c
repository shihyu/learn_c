/*
    字元陣列的初始化
*/

#include  <stdio.h>

int main(void) {
    char  cary[3] = "ABC";  /*空字元將不被附加 */

    printf("cary[0] = \'%c\'\n", cary[0]);
    printf("cary[1] = \'%c\'\n", cary[1]);
    printf("cary[2] = \'%c\'\n", cary[2]);

    system("PAUSE");
    return (0);
}
