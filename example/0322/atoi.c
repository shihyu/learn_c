// gcc -Wall -g atoi.c -o atoi -lm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long long my_atoi(char *s) {
    int i, len;
    long long sum = 0;

    len = strlen(s) - 1;

    // printf("len=%d\n",len);

    for (i = 0; i < len; ++i) {
        sum += (s[i] - '0') * (long long)                                pow(10.0, (double)(len - i - 1));
    }

    return sum;
}

int main() {
    long long value;
    char buffer[25];

    printf("Enter a number: ");
    fgets(buffer, 256, stdin);  // 鍵盤輸入數值存入buffer

    // getchar();

    value = my_atoi(buffer);

    printf("\nThe value entered is %lld.\n", value);
    return 0;
}
