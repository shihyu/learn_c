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
    struct employee e1, e2;

    memset(&e1, 0, sizeof(e1));

    strcpy(e1.name, "zhangsan");

    e1.birthday.year = 1989;
    e1.birthday.month = 11;
    e1.birthday.day = 10;

    e1.gender = 'w';
    strcpy(e1.address, "Suzhou");
    e1.salary = 6100.9;

    e2 = e1;
    printf("information e1:%s %d-%d-%d %c %s %f\n", e1.name, e1.birthday.year,
            e1.birthday.month, e1.birthday.day, e1.gender, e1.address, e1.salary);

    printf("information e2:%s %d-%d-%d %c %s %f\n", e1.name, e1.birthday.year,
            e1.birthday.month, e1.birthday.day, e1.gender, e1.address, e1.salary);

    if (memcmp(&e1, &e2, sizeof(struct employee)) == 0)
        printf("e1 = e2\n");
    else
        printf("e1 != e2\n");


    return 0;
}
