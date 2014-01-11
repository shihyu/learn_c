/* score.c */
#include <stdio.h>
int main() {
    int score;
    printf("輸入成績: ");
    scanf("%d", &score);

    if (score >= 90) {
        printf("甲\n");
    } else if (score >= 80) {
        printf("乙\n");
    } else if (score >= 70) {
        printf("丙\n");
    } else if (score >= 60) {
        printf("丁\n");
    } else {
        printf("不及格\n");
    }
}
