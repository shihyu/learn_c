/*
求出英語和數學成績中的最高分
*/

#include  <stdio.h>

#define  NUMBER   5

/*---傳回元素個數no的陣列vc之最大值---*/
int max_of(int vc[], int no) {
    int     i;
    int  max = vc[0];

    for (i = 1; i < no; i++)
        if (vc[i] > max) {
            max = vc[i];
        }

    return (max);
}

int main(void) {
    int    i;
    int    eng[NUMBER];     /* 數學成績 */
    int    mat[NUMBER];     /* 英文成績 */
    int    max_e, max_m;    /* 最高分 */

    printf("請輸入%d名學生的成績。\n", NUMBER);

    for (i = 0; i < NUMBER; i++) {
        printf("[%d] 英語：", i + 1);
        scanf("%d", &eng[i]);
        printf("    數學：");
        scanf("%d", &mat[i]);
    }

    max_e = max_of(eng, NUMBER);    /* 英文最高分 */
    max_m = max_of(mat, NUMBER);    /* 數學最高分 */

    printf("英文最高分=%d\n", max_e);
    printf("數學最高分=%d\n", max_m);

    return (0);
}

