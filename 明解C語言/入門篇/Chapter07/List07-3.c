/*
判斷char型態為帶符號或不帶符號型態
*/

#include  <stdio.h>
#include  <limits.h>

int main(void) {
    printf("本作業系統的char型態為");

    if (CHAR_MIN) {
        puts("帶符號");
    } else {
        puts("不帶符號");
    }

    return (0);
}
