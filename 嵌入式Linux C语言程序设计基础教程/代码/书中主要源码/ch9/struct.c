#include <stdio.h>
#include <string.h>
#define N 64

struct employee
{
    char name[N];
    int age;
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

    printf("age:");
    scanf("%d", &e1.age);

    getchar();
    printf("gender:");
    scanf("%c", &e1.gender);

    printf("address:");
    scanf("%s", e1.address);

    printf("salary:");
    scanf("%f", &e1.salary);


    printf("\ninformation:%s %d %c %s %f\n", e1.name, e1.age,
            e1.gender, e1.address, e1.salary);

    return 0;
}
