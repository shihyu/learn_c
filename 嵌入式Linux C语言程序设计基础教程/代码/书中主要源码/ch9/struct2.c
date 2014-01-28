#include <stdio.h>
#include <string.h>
#define N 64

struct employee
{
    char name[N];
    struct 
    {
        int year;
        int month;
        int day;
    }birthday;
    char gender;
    char address[N];
    float salary;
};

int main()
{
    struct employee e1;

    memset(&e1, 0, sizeof(e1));

    printf("name:");
    scanf("%s", e1.name);

    printf("year:");
    scanf("%d", &e1.birthday.year);

    printf("month:");
    scanf("%d", &e1.birthday.month);

    printf("day:");
    scanf("%d", &e1.birthday.day);

    getchar();
    printf("gender:");
    scanf("%c", &e1.gender);

    printf("address:");
    scanf("%s", e1.address);

    printf("salary:");
    scanf("%f", &e1.salary);

    printf("\ninformation:%s %d-%d-%d %c %s %f\n", e1.name, e1.birthday.year,
            e1.birthday.month, e1.birthday.day, e1.gender, e1.address, e1.salary);

    return 0;
}
