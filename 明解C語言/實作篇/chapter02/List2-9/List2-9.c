/*
    有號整數與無號整數的比較(利用條件運算子)
*/

#include  <stdio.h>

int main(void) {
    int       sdata = -1;       /*有號整數*/
    unsigned  udata =  1;       /*無號整數*/

    printf("sdata < udata也就是說-1 < 1U為 %s 。\n",
           (sdata < udata) ? "真" : "假");

    printf("(unsigned)sdata < udata 也就是說 "
           "(unsigned) -1 < 1U 是 %s 。\n",
           ((unsigned)sdata < udata) ? "真" : "假");

    system("PAUSE");
    return (0);
}
