/*
對5名學生的《身高》由小而大進行排序
*/

#include <stdio.h>

#define  NUMBER  5                 /*學生人數*/

/*---x和y指到的整數值互換---*/
void swap(int* x, int* y) {
    int  temp = *x;
    *x = *y;
    *y = temp;
}

/*---對陣列data前n個元素由小而大進行排序---*/
void sort(int data[], int n) {
    int  k = n - 1;

    while (k >= 0) {
        int   i, j;

        for (i = 1, j = -1; i <= k; i++)
            if (data[i - 1] > data[i]) {
                j = i - 1;
                swap(&data[i], &data[j]);
            }

        k = j;
    }
}

int main(void) {
    int  i;
    int  height[] = {178, 175, 173, 165, 179};

    sort(height, NUMBER);

    for (i = 0; i < NUMBER; i++) {
        printf("%2d:%4d\n", i + 1, height[i]);
    }

    return (0);
}
