/***************************
    檔名:ch5_18.c
    功能:while迴圈的示範
 ***************************/

#include <stdio.h>
#include <stdlib.h>

void main(void) {
    int x, y, gcd, temp;
    printf("輸入x:");
    scanf("%d", &x);
    printf("輸入y:");
    scanf("%d", &y);
    printf("(%d,%d)=", x, y);

    if (x < y) {      /* 將較大的數值放在x,較小的放在y */
        temp = x;
        x = y;
        y = temp;    /* x,y數值對調 */
    }

    while (x != 0) {
        x = x % y;

        if (x != 0) {
            temp = x;
            x = y;
            y = temp;    /* x,y數值對調 */
        }
    }

    gcd = y;
    printf("%d\n", gcd);
    /*  system("pause");  */
}
