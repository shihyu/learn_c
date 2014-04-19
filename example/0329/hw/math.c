#include <stdio.h>

int main(int argc, char const *argv[]) {
    int count = 100000;
    int i = 0;

    for (i = 0; i < count; ++i) {
        if (i % 11 == 3 && i % 8 == 4 && i % 7 == 1) {
            printf("%d\n", i);
        }
    }

    return 0;
}