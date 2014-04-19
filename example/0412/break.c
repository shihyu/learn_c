#include <stdio.h>

int main(int argc, char *argv[]) {
    int i, j;

    for (i = 0; i < 10; ++i) {


        for (j = 0; j < i; ++j) {
            if (j > 1) {
                break;
            }
        }

        printf("i=%d\n", i);

    }

    return 0;
}
