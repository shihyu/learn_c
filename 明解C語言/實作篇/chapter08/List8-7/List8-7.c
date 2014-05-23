/*
    製作出字串"No.01", "No.02", … , "No.20"
*/

#include  <stdio.h>

int main(void) {
    int   i;
    char  ns[20][6];

    for (i = 0; i < 20; i++) {
        sprintf(ns[i], "No.%02d", i + 1);
    }

    for (i = 0; i < 20; i++) {
        printf("%s\n", ns[i]);
    }

    system("PAUSE");
    return (0);
}
