#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 20
struct employee
{
    char *name;
    int age;
    float salary;
};

int main()
{
    struct employee *p;

    if ((p = (struct employee *)malloc(sizeof(struct employee))) == NULL)
    {
        printf("malloc struct error");
        return 0;
    }
    memset(p, 0, sizeof(struct employee));

    printf("&p=%p sizeof(struct employee)=%d p=%p \n&p->name=%p &p->age=%p &p->salary=%p\n", 
            &p, sizeof(struct employee),
            p, &p->name, &p->age, &p->salary);

    if ((p->name = (char *)malloc(N)) == NULL)
    {
        printf("malloc name error");
        return 0;
    }
    printf("p->name=%p\n", p->name);

    printf("name:");
    scanf("%s", p->name);

    getchar();
    printf("age:");
    scanf("%d", &p->age);

    printf("salary:");
    scanf("%f", &p->salary);

    printf("\ninformation: name:%s age:%d salary:%f\n",
            p->name, p->age, p->salary);


    free(p->name);
    p->name = NULL;

    free(p);
    p = NULL;

    return 0;
}
