#include <stdio.h>
#include <string.h>

struct birth
{
    int year;
    int month;
    int day;
};

typedef struct //worker
{
    char gender;
    short no;
    char name[20];
    struct birth birthday;
}Worker, *Wlink;//struct worker--Worker   struct worker * --- Wlink

Worker gw[3] = {{'m', 1001, "zhangsan", {1999, 2, 1}},
    {'w', 999, "lisi", {2000, 10, 1}},
    {'w', 1009, "wangwu", {1998, 10, 1}}};

void getinfo(Wlink w, int n);
void putinfo(Wlink w, int n);

int main()
{
    Worker w[2];

    getinfo(w, 2);
//    putinfo(w, 2);

    Wlink p = w;
    int i;
    for (i = 0; i < 2; i++)
    {
        printf("********************\n");
        printf("%d %s %c %d-%d-%d\n", p->no, p->name, p->gender,
            p->birthday.year, p->birthday.month, p->birthday.day);
        p++;
    }

    return 0;
}

void getinfo(Wlink w, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("no:");
        scanf("%d", &w[i].no);
        getchar();
        printf("gender:");
        scanf("%c", &w[i].gender);
        printf("name:");
        scanf("%s", w[i].name);
        printf("year:");
        scanf("%d", &w[i].birthday.year);
        printf("month:");
        scanf("%d", &w[i].birthday.month);
        printf("day:");
        scanf("%d", &w[i].birthday.day);
    }
}

void putinfo(Wlink p, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("********************\n");
        printf("%d %s %c %d-%d-%d\n", p->no, p->name, p->gender,
            p->birthday.year, p->birthday.month, p->birthday.day);
        p++;
    }

}
