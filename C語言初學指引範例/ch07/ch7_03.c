/***************************
    檔名:ch7_03.c
    功能:函式應用
 ***************************/

#include <stdio.h>
#include <stdlib.h>

int Odd(int U);
int Even(int U);
int TotalSum(int U);

int main(void) {
    int n, Sum;
    char AddChoice;
    printf("1+2+...+n=?請輸入n=");
    scanf("%d", &n);
    fflush(stdin);
    printf("請問要做奇數和(O),偶數和(E),還是整數和(I)?請選擇:");
    scanf("%c", &AddChoice);

    switch (AddChoice) {
    case 'O':
        Sum = Odd(n);
        break;

    case 'E':
        Sum = Even(n);
        break;

    case 'I':
        Sum = TotalSum(n);
        break;

    default:
        printf("選擇錯誤\n");
        return -1;
    }

    printf("總和為%d\n", Sum);
    /*  system("pause");  */
}

int Odd(int U) {
    int i, total = 0;

    for (i = 1; i <= U; i++)
        if (i % 2 == 1) {
            total = total + i;
        }

    return total;
}

int Even(int U) {
    int i, total = 0;

    for (i = 1; i <= U; i++)
        if (i % 2 == 0) {
            total = total + i;
        }

    return total;
}

int TotalSum(int U) {
    return Odd(U) + Even(U);
}
