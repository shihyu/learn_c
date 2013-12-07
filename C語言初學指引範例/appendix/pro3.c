/****  檔名:pro3.c   功能:gdb示範  *****/
#include <stdio.h>

void cal_ele(int i, int* add_ary, int* mul_ary);

int main(void) {
    int add_ary[5] = {0};
    int mul_ary[5] = {1};
    int i;

    for (i = 1; i < 10; i++) {
        cal_ele(i, add_ary, mul_ary);
    }

    for (i = 0; i < 5; i++) {
        printf("add_ary[%d]=%d\n", i, add_ary[i]);
    }

    printf("---------------------\n");

    for (i = 0; i < 5; i++) {
        printf("mul_ary[%d]=%d\n", i, mul_ary[i]);
    }
}

void cal_ele(int i, int* add_ary, int* mul_ary) {
    add_ary[i] = add_ary[i - 1] + i;
    mul_ary[i] = mul_ary[i - 1] * i;
}
