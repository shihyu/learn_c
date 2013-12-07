/*******************************
    檔名:ch10_08.c
    功能:列舉資料型態
 *******************************/

#include <stdio.h>
#include <stdlib.h>

enum manufacturer {IBM, MAXTOR, WD, SEAGATE};

int main(void) {
    enum manufacturer HardDisk;
    printf("%d\n", IBM);

    switch (IBM) {
    case 0:
        printf("硬碟廠牌是IBM\n");
        break;

    case 1:
        printf("硬碟廠牌是MAXTOR\n");
        break;

    case 2:
        printf("硬碟廠牌是WD\n");
        break;

    case 3:
        printf("硬碟廠牌是SEAGATE\n");
        break;
    }

    system("pause");
    return 0;
}
