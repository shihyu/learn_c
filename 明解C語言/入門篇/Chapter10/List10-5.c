/*
兩整數互換
*/

#include  <stdio.h>

/*---nx與ny指到的物件之值互換---*/
void swap(int* nx, int* ny) {
    int  temp = *nx;
    *nx = *ny;
    *ny = temp;
}

int main(void) {
    int  na, nb;

    puts("請輸入兩個整數：");
    printf("整數A：");
    scanf("%d", &na);
    printf("整數B：");
    scanf("%d", &nb);

    swap(&na, &nb);

    puts("兩值互換後：");
    printf("整數A為%d。\n", na);
    printf("整數B為%d。\n", nb);

    return (0);
}
