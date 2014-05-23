/*
對5名學生的《名字與身高》按照身高由小而大進行排序
*/

#include  <stdio.h>
#include  <string.h>

#define   NUMBER  5                         /*學生人數*/

/*---x和y指到的整數值互換---*/
void swap(int* x, int* y) {
    int  temp = *x;
    *x = *y;
    *y = temp;
}

/*---sx和sy指到的字串互換---*/
void swaps(char sx[], char sy[]) {
    char temp[256];

    strcpy(temp, sx);
    strcpy(sx, sy);
    strcpy(sy, temp);
}

/*---對陣列data和name前n個元素由小而大進行排序---*/
void sort(int data[], char name[][20], int n) {
    int  k = n - 1;

    while (k >= 0) {
        int   i, j;

        for (i = 1, j = -1; i <= k; i++)
            if (data[i - 1] > data[i]) {
                j = i - 1;
                swap(&data[i], &data[j]);
                swaps(name[i], name[j]);
            }

        k = j;
    }
}

int main(void) {
    int   i;
    int   height[] = {178, 175, 173, 165, 179};
    char  name[][20] = {"Sato", "Sanaka", "Takao", "Mike", "Masaki"};

    sort(height, name, NUMBER);

    for (i = 0; i < NUMBER; i++) {
        printf("%2d:%-8s%4d\n", i + 1, name[i], height[i]);
    }

    return (0);
}
