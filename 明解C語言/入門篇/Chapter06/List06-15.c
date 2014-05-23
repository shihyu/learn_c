/*---循序搜尋（哨待法）--- */
#include  <stdio.h>

#define  NUMBER    5
#define  FAILED   -1

/*--- 以哨待法進行循序搜尋 ---*/
int search(int vc[], int key, int no) {
    int     i = 0;

    vc[no] = key;   /* 追加哨待 */

    while (1) {
        if (vc[i] == key) {
            break;
        }

        i++;
    }

    return (i == no ? FAILED : i);
}

int main(void) {
    int  i, ky, idx;
    int  vx[NUMBER + 1];

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
        printf("%d就在第%d的位置。\n", ky, idx + 1);
    }

    return (0);
}
