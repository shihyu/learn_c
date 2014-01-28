#include <stdio.h>

int main(int argc, char *argv[])
{
    int max, i, j, r, c;
    int a[3][4] ={{24, 89, 2, 41}, {3, 11, 9, 1}};

    max = a[0][0];

    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
            if (a[i][j] > max)
            {
                max = a[i][j];
                r = i;
                c = j;
            }

    printf("max=%d, row=%d, column=%d\n", max, r, c);

    return 0;
}
