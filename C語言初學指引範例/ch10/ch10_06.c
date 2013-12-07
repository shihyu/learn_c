/*******************************
    檔名:ch10_06.c
    功能:struct位元欄位練習
 *******************************/

#include <stdio.h>
#include <stdlib.h>

struct flag {
    unsigned short int f1: 1;
    unsigned short int f2: 2;
};

void main(void) {
    struct flag PSW;
    PSW.f1 = 1;
    PSW.f2 = 2;

    if (PSW.f1 == 1) {
        printf("f1 is ON\n");
    } else {
        printf("f1 is OFF\n");
    }

    switch (PSW.f2) {
    case 0:
        printf("f2 is OFF-OFF\n");
        break;

    case 1:
        printf("f2 is OFF-ON\n");
        break;

    case 2:
        printf("f2 is ON-OFF\n");
        break;

    case 3:
        printf("f2 is ON-ON\n");
        break;
    }

    /* system("pause"); */
}
