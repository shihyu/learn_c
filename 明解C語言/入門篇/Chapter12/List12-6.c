/*
具有超能力的lily（第二版）
*/

#include  <stdio.h>

/*---輸出學生的結構---*/
typedef struct {
    char   name[20];    /* 姓名 */
    int    height;      /* 身高 */
    float  weight;      /* 體重 */
    long   schols;      /* 獎學金 */
} student;

/*---lily發揮超能力拉長身高、減少體重---*/
void lily(student* std) {
    if (std->height < 180) {
        std->height = 180;
    }

    if (std->weight >  80) {
        std->weight =  80;
    }
}

int main(void) {
    student  soong  = {"Soong", 175, 60.5, 70000};

    lily(&soong);

    printf("姓　名 = %s\n",  soong.name);
    printf("身　高 = %d\n",  soong.height);
    printf("體　重 = %f\n",  soong.weight);
    printf("獎學金 = %ld\n", soong.schols);

    return (0);
}
