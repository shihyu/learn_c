#include <stdio.h>

struct Stack {
    int item[9];
    int top;
};

int main(int argc, char *argv[]) {

    struct Stack S;
    struct Stack *p = &S;

    S.top = -1;
    S.item[0] = 100;
    S.item[1] = 200;
    S.item[2] = 300;
    S.item[3] = 400;
    S.item[4] = 500;
    S.item[5] = 600;
    S.item[6] = 700;
    S.item[7] = 800;
    S.item[8] = 900;



    printf("%d\n", p->top);

    printf("%d\n", p->item[0]);
    printf("%d\n", p->item[1]);
    printf("%d\n", p->item[2]);
    printf("%d\n", p->item[3]);
    printf("%d\n", p->item[7]);
    printf("%d\n", p->item[8]);


    return 0;
}
