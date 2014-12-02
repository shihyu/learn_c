#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
#if 0
    int check_ascii_bool = 1;
    int num, i;
    char input_string[20];
    char check_ascii;

    puts("Please enter a num: ");
    scanf("%s", input_string);

    for (i = 0; input_string[i] != '\0'; i++) {
        check_ascii = input_string[i];

        if ((check_ascii < '0') || (check_ascii > '9')) {
            check_ascii_bool = 0;
        }
    }

    if (check_ascii_bool) {
        num = atoi(input_string);

        printf("%d\n", num);

        if (num == 0) {
            puts("The number you entered is 0 ");
        } else if (num >= 0) {
            puts("The number you entered is Positive ");
        } else if (num <= 0) {
            puts("The number you entered is Negative ");
        } else {
            puts("Unexpected Errors!");
        }
    } else {
        printf("input error!!\n");
    }

    return 0;
#else
    int digit;
    printf("please input a integer\n");
    int ret = scanf("%d", &digit);

    if (0 == ret) {
        printf("you should input a integer\n");
    } else {
        printf("%d\n", digit);
    }

    
    return 0;
#endif
}
