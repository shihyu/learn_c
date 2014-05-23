/*
    附符號整數與無符號整數的比較
*/

#include  <stdio.h>

int main(void) {
    int       sdata = -1;       /*附符號整數*/
    unsigned  udata =  1;       /*無符號整數*/

    printf("sdata < udata 也就是說 -1 < 1U是 ");

    if (sdata < udata) {
        puts("真");
    } else {
        puts("假");
    }

    printf("sdata < (int) udata 也就是說，-1 < (int) 1U是 ");

    if (sdata < (int)udata) {
        puts("真");
    } else {
        puts("假");
    }

    system("PAUSE");
    return (0);
}
