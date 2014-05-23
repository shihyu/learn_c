/*
    學生的結構體中的宋小瑜被初始化
*/

#include  <stdio.h>

struct gstudent {
    char   name[20];     /* 名字 */
    int      height;     /* 身高 */
    float  weight;       /* 體重 */
    long   schols;       /* 獎學金 */
};

int main(void) {
    struct gstudent  soong  = {"Soong", 175, 60.5};

    printf("姓　名 = %s\n",  soong.name);
    printf("身　高 = %d\n",  soong.height);
    printf("體　重 = %f\n",  soong.weight);
    printf("獎學金 = %ld\n", soong.schols);

    return (0);
}
