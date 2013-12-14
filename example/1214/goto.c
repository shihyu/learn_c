/***************************
    檔名:ch5_20.c
    功能:goto敘述的示範
 ***************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int Sum, FactNum, x, y, m;
    printf("計算1!+2!+...+m!,(0<m<10)\n");
    printf("請輸入m:");
    scanf("%d", &m);

    for (Sum = 0, x = 1; x < 10; x++) {
        for (FactNum = 1, y = 1; y <= x; y++) {
            FactNum = FactNum * y;

            if (y == m + 1) {
                goto ProgEnd;
            }
        }

        Sum = Sum + FactNum;
    }

ProgEnd:
    printf("1!+2!+...+m!=%d(m=%d)\n", Sum, m);
    /*  system("pause");  */

    return 0;

}
