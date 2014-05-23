/*
驗證無註標運算子的陣列名稱之值（指向前端元素的指標）
*/

#include  <stdio.h>

int main(void) {
    int  vc[3];

    printf("vc         ：%p\n", vc);
    printf("vc[0]的位址：%p\n", &vc[0]);
    printf("vc[1]的位址：%p\n", &vc[1]);
    printf("vc[2]的位址：%p\n", &vc[2]);

    return (0);
}
