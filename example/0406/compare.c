#include <stdlib.h>
#include <stdio.h>

int main() {
    int a = 100, b = 50, c = 60;

    if (a > b) {
        if (b > c) {
            printf("%d>%d>%d\n", a, b, c);
        } else { //c < b
            if (a > c) {
                printf("%d>%d>%d\n", a, c, b);
            } else {
                printf("%d>%d>%d\n", c, a, b);
            }
        }
    } else { //b>a
        if (a > c) {
            printf("%d>%d>%d\n", b, a, c);
        } else { //c > a
            if (b > c) {
                printf("%d>%d>%d\n", b, c, a);
            } else { //c>b
                printf("%d>%d>%d\n", c, b, a);
            }
        }
    }

    return 0;
}
