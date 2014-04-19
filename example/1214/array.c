#include <stdio.h>

int main(int argc, char *argv[]) {
    int i, j;
    int a[10];
    char b[10];
    int d[5] = {100, 200, 300, 400, 500};
#if 1
    int c[2][4] = {{10, 20, 30, 40},
        {50, 60, 70, 80 }
    };
#else
    int c[2][4] = {10, 20, 30, 40, 50, 60, 70, 80};
#endif
    printf("%ld\n", sizeof(a));
    printf("%ld\n", sizeof(b));
    printf("%ld\n", sizeof(c));

    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 4; ++j) {
            printf("%d,", c[i][j]);
        }

        printf("\n");
    }

    //  array 在運算表達式是以指標型態運算
    for (i = 0; i < 5; ++i) {
        // 三個是等價關係
        printf("%d,", *(d + i)); // 指標形式
        printf("%d,", i[d]);
        printf("%d,", d[i]); // 正常陣列形式
    }

    return 0;
}
