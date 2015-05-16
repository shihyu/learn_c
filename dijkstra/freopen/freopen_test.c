#include<stdio.h>
int main()
{
    int item, x, y;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (scanf("%d%d%d", &item, &x, &y) == 3) {
        printf("%d %d %d %d ", item, x, y, x + y);

        if (x + y < 140) {
            printf("不合格\n");
        } else {
            printf("合格\n");
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
