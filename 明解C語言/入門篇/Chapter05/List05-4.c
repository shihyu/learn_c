/*
  將陣列中的所有元素指定為0.0後並輸出
*/
#include  <stdio.h>

int main(void) {
    int  i;
    double vd[5];                    /*元素個數為5的陣列*/

    for (i = 0; i < 5; i++) {
        vd[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
        printf("vd[%d] = %.1f\n", i, vd[i]);
    }

    return (0);
}
