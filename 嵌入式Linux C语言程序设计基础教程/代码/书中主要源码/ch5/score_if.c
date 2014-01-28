#include <stdio.h>

int main()
{
    float score;

    printf("input score:");
    scanf("%f", &score);

    if (score < 0 || score > 100)
    {
        printf("score is invalid\n");
        return 0;
    }

    if (score >= 90)
        printf("A\n");
    if (score >= 80 && score < 90)
        printf("B\n");
    if (score >= 70 && score < 80)
        printf("C\n");
    if (score >= 60 && score < 70)
        printf("D\n");
    if (score < 60)
        printf("E\n");

    return 0;
}
