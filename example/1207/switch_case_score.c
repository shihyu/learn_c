/*******************************
    檔名:ch5_12.c
    功能:falling through的示範
 *******************************/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int Score;
    printf("請輸入計概成績:");
    scanf("%d", &Score);

    if ((Score >= 0) && (Score <= 100)) {
        switch (Score / 10) {
        case 10:
            printf("完美分數\n");

        case 9:
            printf("分數等級為優等\n");

        case 8:
            printf("分數等級為甲等\n");

        case 7:
            printf("分數等級為乙等\n");

        case 6:
            printf("分數等級為丙等\n");

        default:
            printf("分數等級為丁等\n");
        }
    }
    return 0;
}
