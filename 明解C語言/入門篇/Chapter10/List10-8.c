/*
由小而大排列兩個整數
*/

#include  <stdio.h>

/*---nx與ny指到的物件之值互換---*/
void swap(int* nx, int* ny) {
    int   temp = *nx;
    *nx = *ny;
    *ny = temp;
}
/*---排成n1≦n2---*/
void sort2(int* n1, int* n2) {
    if (*n1 > *n2) {
        swap(n1, n2);
    }
}

int main(void) {
    int  na, nb;

    puts("請輸入兩個整數：");
    printf("整數A：");
    scanf("%d", &na);
    printf("整數B：");
    scanf("%d", &nb);

    sort2(&na, &nb);

    puts("將兩值由小而大重排的結果。");
    printf("整數A為%d。\n", na);
    printf("整數B為%d。\n", nb);

    return (0);
}
