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
}e1 = {"zhangsan", {1980, 9, 4}, 'w', "Shanghai", 3400};

int main()
{
    struct employee e2 = {"lisi", {1990, 12, 4}, 'w', "Guangzhou", 8400};

    printf("information e1:%s %d-%d-%d %c %s %f\n", e1.name, e1.birthday.year,
            e1.birthday.month, e1.birthday.day, e1.gender, e1.address, e1.salary);

    printf("information e2:%s %d-%d-%d %c %s %f\n", e2.name, e2.birthday.year,
            e2.birthday.month, e2.birthday.day, e2.gender, e2.address, e2.salary);


    return 0;
}
