/* system1.c */
#include <stdio.h>
#include <stdlib.h>
int main() {
    int myret;
    myret = system("ls -l");
    return 0;
}
