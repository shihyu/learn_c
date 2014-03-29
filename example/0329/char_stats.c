// gcc -Wall -g atoi.c -o atoi -lm

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void my_char_stats(char* buffer, int char_stats[]) {
    int i, len;

    len = strlen(buffer) - 1;
    printf("len=%d\n",len);

    for (i = 0; i < len; ++i) {
        printf("%c ",buffer[i]);
        printf("%d ",buffer[i]);
        char_stats[ buffer[i] - 'a' ]++;

    }

    printf("\n\n\n\n");

    for (i = 0; i < 26; ++i)
    {
        printf("%d ",char_stats[i]);
    }
}

int main() {
    int i;
    char buffer[256];
    int char_stats[26];

    printf("Enter a string: ");
    fgets(buffer, 256, stdin);  // 鍵盤輸入數值存入buffer 
    // getchar();
    
    for (i = 0; i < 26; ++i) {
        char_stats[i] = 0;
    }

    my_char_stats(buffer, char_stats);

    return 0;
}
