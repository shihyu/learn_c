/*
比較指標
*/

#include  <stdio.h>

int main(void) {
    int  vc[3];
    int*  ptr = vc;

    printf(" vc    ==  ptr   : %d\n", vc     == ptr);
    printf("&vc[1] <= &vc[1] : %d\n", &vc[1] <= &vc[1]);
    printf("&vc[1] <  &vc[2] : %d\n", &vc[1] <  &vc[2]);
    printf("&vc[2] -  &vc[0] : %d\n", &vc[2] -  &vc[0]);

    return (0);
}
