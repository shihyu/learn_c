/*
    確認2維陣列的初始化
*/

#include  <stdio.h>

int main(void) {
    int  i, j;
    int  x[3][2] = {{0, 1},
        {2, 3},
        {4, 5},
    };

    for (i = 0; i < 3; i++)
        for (j = 0; j < 2; j++) {
            printf("a[%d][%d] = %d\n", i, j, x[i][j]);
        }

    system("PAUSE");
    return (0);
}
