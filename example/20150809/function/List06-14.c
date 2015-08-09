/*
循序搜尋
 */

#include  <stdio.h>

#define    NUMBER       5
#define    FAILED       -1

/*--- 在元素個數no的陣列vc尋找與key相符的元素 ---*/
int search(const int vc[], int key, int no) {
    int   i = 0;

    while (1) {
        if (i == no) {
            return (FAILED);    /* 搜尋失敗 */
        }

        if (vc[i] == key) {
            return (i);    /* 搜尋成功 */
        }

        i++;
    }
}

int main(void) {
    int  i, ky, idx;
    int  vx[NUMBER];

    for (i = 0; i < NUMBER; i++) {
        printf("vx[%d]：", i);
        scanf("%d", &vx[i]);
    }

    printf("欲搜尋之值：");
    scanf("%d", &ky);

    idx = search(vx, ky, NUMBER);

    if (idx == FAILED) {
        puts("\a搜尋失敗");
    } else {
        printf("%d就在第%d個位置。\n", ky, idx + 1);
    }

    return (0);
}
