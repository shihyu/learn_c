/*
反序輸出非負數的整數
*/

#include  <stdio.h>

/*---輸入非負數的整數後傳回---*/
int scan_uint(void) {
    int  tmp;

    do {
        printf("請輸入一個非負整數：");
        scanf("%d", &tmp);

        if (tmp < 0) {
            puts("\a請不要輸入負數。");
        }
    } while (tmp < 0);

    return (tmp);
}

/*---請輸入一個非負數的整數：---*/
int rev_int(int num) {
    int  tmp = 0;

    if (num > 0) {
        do {
            tmp = tmp * 10 + num % 10;
            num /= 10;
        } while (num > 0);
    }

    return (tmp);
}

int main(void) {
    int  nx = scan_uint();

    printf("倒轉後之值為%d\n", rev_int(nx));

    return (0);
}
