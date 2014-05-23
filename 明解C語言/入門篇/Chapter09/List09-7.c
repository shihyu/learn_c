/*
讀取字串陣列並輸出
*/
#include  <stdio.h>

int main(void) {
    int   i;
    char  cs[3][128];

    for (i = 0; i < 3; i++) {
        printf("cs[%d]:", i);
        scanf("%s", cs[i]);
    }

    for (i = 0; i < 3; i++) {
        printf("cs[%d]=\"%s\"\n", i, cs[i]);
    }

    return (0);
}
