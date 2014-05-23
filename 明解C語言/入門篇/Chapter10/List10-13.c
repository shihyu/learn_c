/*
陣列的交接
*/

#include  <stdio.h>

void int_set(int vc[], int no, int val) {
    int  i;

    for (i = 0; i < no; i++) {
        vc[i] = val;
    }
}

int main(void) {
    int  i;
    int  ary[] = {1, 2, 3, 4, 5};

    int_set(ary, 5, 0);

    for (i = 0; i < 5; i++) {
        printf("ary[%d] = %d\n", i, ary[i]);
    }

    return (0);
}
