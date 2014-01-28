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

void input(struct employee *p)
{
    printf("name:");
    scanf("%s", p->name);

    printf("age:");
    scanf("%d", &p->age);

    getchar();
    printf("gender:");
    scanf("%c", &p->gender);

    printf("address:");
    scanf("%s", p->address);

    printf("salary:");
    scanf("%f", &p->salary);
}

void output(struct employee *p)
{
    printf("information:%s %d %c %s %f\n", p->name, p->age,
            p->gender, p->address, p->salary);
}

int main()
{
    struct employee e1;

    memset(&e1, 0, sizeof(e1));

    input(&e1);
    output(&e1);

    return 0;
}
