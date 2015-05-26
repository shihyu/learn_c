#include<stdio.h>
#include <unistd.h>

int main()
{
    int item, x, y, fd;

    fd = dup(fileno(stdout));
    fflush(stdout);

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

    fflush(stdout);
    dup2(fd, fileno(stdout));
    close(fd);

    printf("HHHHHH\n");

    return 0;
}
