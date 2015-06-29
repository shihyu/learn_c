#include<stdio.h>
#include <unistd.h>
#include <unistd.h>

int main()
{
    int item, x, y, fd;
    int i, o;

    i = dup(0);
    o = dup(1);

    printf("SSSSSS\n");

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &x);
    scanf("%d", &y);

    printf("%d\n", x);
    printf("%d\n", y);

    while (scanf("%d%d%d", &item, &x, &y) == 3) {
        printf("%d %d %d %d ", item, x, y, x + y);

        if (x + y < 100) {
            printf("距離 < 100 \n");
        } else {
            printf("距離 > 100 \n");
        }
    }

    dup2(i, 0);
    dup2(o, 1);

    printf("HHHHHH\n");
    fflush(stdout);
    getchar();
    return 0;
}
