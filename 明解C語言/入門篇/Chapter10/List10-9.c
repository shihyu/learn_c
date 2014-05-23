/*
兩實數值互換（錯誤的範例）
*/

#include  <stdio.h>

/*---nx與ny指到的物件之值互換---*/
void swap(int* nx, int* ny) {
    int   temp = *nx;
    *nx = *ny;
    *ny = temp;
}

int main(void) {
    double  dx, dy;

    puts("請輸入兩個實數。");
    printf("實數X：");
    scanf("%lf", &dx);
    printf("實數Y：");
    scanf("%lf", &dy);

    swap(&dx, &dy);

    puts("兩值互換後：");
    printf("實數X為%f。\n", dx);
    printf("實數Y為%f。\n", dy);

    return (0);
}
