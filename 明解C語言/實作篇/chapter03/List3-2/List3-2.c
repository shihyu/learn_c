/*
    顯示陣列內元素的位址
*/

#include  <stdio.h>

int main(void) {
    int  x[5];

    printf("x[0]的位址=%p\n", &x[0]);
    printf("x[1]的位址=%p\n", &x[1]);
    printf("x[2]的位址=%p\n", &x[2]);
    printf("x[3]的位址=%p\n", &x[3]);
    printf("x[4]的位址=%p\n", &x[4]);

    system("PAUSE");
    return (0);
}
