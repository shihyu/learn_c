/*
具有超能力的lily
*/

#include  <stdio.h>

struct gstudent {
    char   name[20];     /* 姓名 */
    int     height;      /* 身高 */
    float  weight;       /* 體重 */
    long   schols;       /* 獎學金 */
};

/*---lily發揮超能力拉長身高、減少體重---*/
void lily(struct gstudent* std) {
    if ((*std).height < 180) {
        (*std).height = 180;
    }

    if ((*std).weight >  80) {
        (*std).weight =  80;
    }
}

int main(void) {
    struct gstudent soong = {"Soong", 175, 60.5, 70000};

    lily(&soong);

    printf("姓　名 =  %s\n",  soong.name);
    printf("身　高 =  %d\n",  soong.height);
    printf("體　重 =  %f\n",  soong.weight);
    printf("獎學金 =  %ld\n", soong.schols);

    return (0);
}
