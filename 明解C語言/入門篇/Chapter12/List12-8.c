/*
按照身高由小而大排列出5名學生
*/

#include  <stdio.h>

#define  NUMBER  5           /* 學生人數 */

/*---輸出學生的結構體---*/
typedef struct {
    char   name[20];     /* 姓名 */
    int    height;       /* 身高 */
    float  weight;       /* 體重 */
    long   schols;       /* 獎學金 */
} student;

/*---x和y指到的學生互換---*/
void swap(student* x, student* y) {
    student  temp = *x;
    *x = *y;
    *y = temp;
}

/*---對陣列data前n個元素按照身高由小而大排序---*/
void sort(student data[], int n) {
    int  k = n - 1;

    while (k >= 0) {
        int   i, j;

        for (i = 1, j = -1; i <= k; i++)
            if (data[i - 1].height > data[i].height) {
                j = i - 1;
                swap(&data[i], &data[j]);
            }

        k = j;
    }
}

int main(void) {
    int  i;
    student std[] = {
        { "Soong", 178,    61.0,    80000},       /* 宋小瑜 */
        { "Chang", 175,    60.5,    70000},       /* 張小雄 */
        { "Hsu",   173,    80.0,    0},           /* 許小良 */
        { "Chen",  165,    72.0,    70000},       /* 陳小扁 */
        { "Lin",   179,    77.5,    70000},       /* 林小雄 */
    };

    sort(std, NUMBER);

    puts("-----------------------------");

    for (i = 0; i < NUMBER; i++)
        printf("%-8s %6d%6.1f%7ld\n",
               std[i].name,  std[i].height, std[i].weight, std[i].schols);

    puts("-----------------------------");

    return (0);
}
