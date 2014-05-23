/*
    控制式變成代入式的if文
*/

#include  <stdio.h>

int main(void) {
    int  a, b;

    printf("a的值為 : ");
    scanf("%d", &a);
    printf("b的值為 : ");
    scanf("%d", &b);

    if (a = b) {
        printf("■ a = %d\n■ b = %d\n", a, b);
    } else {
        printf("□ a = %d\n□ b = %d\n", a, b);
    }

    system("PAUSE");
    return (0);
}
