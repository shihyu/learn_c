// 範例:用來減少判斷的次數.
#include <stdio.h>
#define N 10

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    return a / b;
}

int main(void) {
    int (*oper)(int a, int b);
    char key;
    int a[N], b[N], c[N];
    int i;

    for (i = 0; i < N; i++) {
        a[i] = i + 1;
        b[i] = i + 1;
    }

    printf("Press +,-,*,/ for add, sub, mul, div\n");
    key = getchar();

    switch (key) {
        case '+':
            oper = add;
            break;

        case '-':
            oper = sub;
            break;

        case '*':
            oper = mul;
            break;

        case '/':
            oper = div;
            break;
    }

    for (i = 0; i < N; i++) {
        c[i] = oper(a[i], b[i]);
        printf("%d ", c[i]);
    }

    printf("\n");
    return 0;
}
