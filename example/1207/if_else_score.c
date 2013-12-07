/***************************
    檔名:ch5_09.c
    功能:else-if格式的練習
 ***************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned int Score;
    printf("請輸入計概成績:");
    scanf("%d", &Score);

    if (Score < 60) {
        printf("分數等級為丁等\n");
    } else if (Score <= 69) {
        printf("分數等級為丙等\n");
    } else if (Score <= 79) {
        printf("分數等級為乙等\n");
    } else if (Score <= 89) {
        printf("分數等級為甲等\n");
    } else if (Score <= 99) {
        printf("分數等級為優等\n");
    } else if (Score == 100) {
        printf("完美分數\n");
    } else {
        printf("您輸入了不合法的分數\n");
    }
    return 0;
}
