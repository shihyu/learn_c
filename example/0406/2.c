#include <stdio.h>

// 輸入一個數字N,從1+2+3+ ... +N = ?  例如是輸入10 計算出1+2+3+4+5+6+7+8+9+10 = 55 , 印出55
int main(int argc, char *argv[]) {

    int i, value;
    int sum = 0;

    scanf("%d", &value);

    for (i = 1; i <= value; i++) {
        sum += i;
    }

    printf("sum=%d\n", sum);

    return 0;
}
