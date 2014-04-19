#include <stdio.h>

int myadd(int a, int b) {
    return a + b;
}

int main(int argc, char const *argv[]) {
    int a, b;
    int sum;
    printf("please input two integers\n");
    scanf("%d %d", &a, &b);
    sum = myadd(a, b);
    printf("sum=%d\n", sum);

    return 0;
}