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
    else if (score >= 80)
        printf("B\n");
    else if (score >= 70)
        printf("C\n");
    else if (score >= 60)
        printf("D\n");
    else
        printf("E\n");

    return 0;
}
