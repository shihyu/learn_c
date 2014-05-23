/*
    將關係式與等價式評價出來的值顯示的程式
*/

#include  <stdio.h>

int main(void) {
    int  nx, ny;

    printf("請輸入nx的值：");
    scanf("%d", &nx);

    printf("請輸入ny的值：");
    scanf("%d", &ny);

    printf("nx <  ny : %d\n", nx <  ny);
    printf("nx <= ny : %d\n", nx <= ny);
    printf("nx >  ny : %d\n", nx >  ny);
    printf("nx >= ny : %d\n", nx >= ny);
    printf("nx == ny : %d\n", nx == ny);
    printf("nx != ny : %d\n", nx != ny);

    system("PAUSE");
    return (0);
}
