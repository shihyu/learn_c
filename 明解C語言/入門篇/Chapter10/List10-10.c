/*
陣列與指標
*/

#include  <stdio.h>

int main(void) {
    int  i;
    int  vc[5] = {10, 20, 30, 40, 50};
    int*  ptr = &vc[0];

    for (i = 0; i < 5; i++)
        printf("vc[%d] = %d   ptr[%d] = %d   *(ptr + %d) = %d\n",
               i,  vc[i], i, ptr[i], i, *(ptr + i));

    return (0);
}
