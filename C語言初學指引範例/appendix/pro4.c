/****  filename:pro4.c   IDE Demo  *****/

#include <stdio.h>

int main(void) {
    int i, j;

    for (i = 1; i <= 9; i++) {
        for (j = 1; j <= 9; j++) {
            printf("%d*%d=%d\t", i, j, i * j);
        }

        printf("\n");
    }
}
