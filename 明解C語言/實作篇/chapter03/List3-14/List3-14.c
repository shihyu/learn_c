/*
    求出2維陣列各行的加總來做顯示(間接運算子版)
*/

#include  <stdio.h>

/*--- 求出2維陣列z的各行加總來做顯示 ---*/
void sum(double(*z)[3], int n) {
    int  i, j;

    for (i = 0; i < n; i++) {
        double  sum = 0.0;

        for (j = 0; j < 3; j++) {
            sum += (*z)[j];
        }

        printf("第%d行的合計=%5.1f\n", i, sum);
        z++;
    }
}

int main(void) {
    double  goukei;                         /*合計*/
    double  x[][3] = {{0.0, 0.0, 0.0},
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0},
        {7.0, 8.0, 9.0},
    };

    int  nx = sizeof(x) / sizeof(x[0]); /*陣列x的元素數(行數) */

    sum(x, nx);

    system("PAUSE");
    return (0);
}
