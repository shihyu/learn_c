#include <stdio.h>

int main(int argc, char* argv[]) {
    int score;
    scanf("%d", &score);
    // 整數判斷非0之外都是true
#if 0

    if (100) {
        printf("true");
    } else {
        printf("false");
    }

#endif

    if (score >= 90) {
        printf("A");
    } else if (score >= 80) {
        printf("B");
    } else if (score >= 70) {
        printf("C");
    } else if (score >= 60) {
        printf("D");
    } else {
        printf("不及格");
    }

    return 0;
}
