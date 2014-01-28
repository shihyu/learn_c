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
}e1[2] = { {"zhangsan", {1980, 9, 4}, 'w', "Shanghai", 3400}, 
           {"lisi", {1991, 10, 24}, 'w', "Hebei", 3400}};

int main()
{
    struct employee e2[2] = {{"wangwu", {1986, 2, 24}, 'w', "Hubei", 6400}, 
                             {"Lucy", {1986, 8, 14}, 'w', "Henan", 3421}};
    int i;

    for (i = 0; i < sizeof(e1)/sizeof(struct employee); i++)
        printf("information :%s %d-%d-%d %c %s %f\n", e1[i].name, 
                e1[i].birthday.year, e1[i].birthday.month, e1[i].birthday.day, 
                e1[i].gender, e1[i].address, e1[i].salary);

    printf("\n");

    for (i = 0; i < sizeof(e2)/sizeof(struct employee); i++)
        printf("information :%s %d-%d-%d %c %s %f\n", e2[i].name, 
                e2[i].birthday.year, e2[i].birthday.month, e2[i].birthday.day, 
                e2[i].gender, e2[i].address, e2[i].salary);

    return 0;
}
