// 這個程式如果不用函式指標來寫, switch 就必須放在迴圈當中, 每次迴圈都要做一次判斷.
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
    char key;
    int a[N], b[N], c[N];
    int i;

    for (i = 0; i < N; i++) {
        a[i] = i + 1;
        b[i] = i + 1;
    }

    printf("Press +,-,*,/ for add, sub, mul, div\n");
    key = getchar();

    for (i = 0; i < N; i++) {
        switch (key) {
            case 'a':
                c[i] = add(a[i], b[i]);
                break;

            case 's':
                c[i] = sub(a[i], b[i]);
                break;

            case 'm':
                c[i] = mul(a[i], b[i]);
                break;

            case 'd':
                c[i] = div(a[i], b[i]);
                break;

            default:
                printf("key error");
                break;
        }

        printf("%d ", c[i]);
    }

    printf("\n");
    return 0;
}
