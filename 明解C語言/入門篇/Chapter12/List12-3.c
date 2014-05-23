/*
輸出學生的結構體中的宋小瑜
*/

#include  <stdio.h>
#include  <string.h>

struct gstudent {
    char   name[20];     /* 姓名 */
    int    height;       /* 身高 */
    float  weight;       /* 體重 */
    long   schols;       /* 獎學金 */
};

int main(void) {
    struct gstudent soong;

    strcpy(soong.name, "Soong");    /* 姓名 */
    soong.height = 175;             /* 身高 */
    soong.weight = 60.5;            /* 體重 */
    soong.schols = 70000;           /* 獎學金 */

    printf("姓　名 = %s\n",  soong.name);
    printf("身　高 = %d\n",  soong.height);
    printf("體　重 = %f\n",  soong.weight);
    printf("獎學金 = %ld\n", soong.schols);
    system("PAUSE");
    return (0);
}
