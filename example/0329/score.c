#include <stdio.h>

char my_score_level(int score) {
    
    if (score > 100 || score < 0) {
        printf("input format error!!\n");
        return 'N';
    }


    if (score >= 90 && score <= 100) {
        return 'A';
    } else if (score <= 89 && score >= 80) {
        return 'B';
    } else if (score <= 79 && score >= 70) {
        return 'C';
    } else if (score <= 69 && score >= 60) {
        return 'D';
    } else {
        return 'E';
    }
}

int main(int argc, char* argv[]) {
    int c;
    int score;
    scanf("%d", &score);
    printf("%d\n", score);

    c = my_score_level(score);

    printf("%d<-->",c);
    printf("%c",c);
    return 0;
}
