#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct node
{
    datatype data;
    struct node *next;
}listnode, *linklist;

linklist linklist_create(int n)
{
    int i;
    linklist H, p, q;
    H = (linklist)malloc(sizeof(listnode));
    if (H == NULL)
    {
        printf("malloc error\n");
        return H;
    }
    H->data = 1;
    H->next = H;
    p = H;

    i = 2;
    while (i <= n)
    {
        q = (linklist)malloc(sizeof(listnode));
        if (q == NULL)
        {
            printf("malloc error\n");
            return q;
        }
        q->data = i;
        p->next = q;
        q->next = H;
        p = q;
        i++;
    }

    return H;
}

void linklist_show(linklist H)
{
    linklist p = H;

    while (p->next != H)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("%d\n", p->data);
}

int jose(linklist H, int k, int m)
{
    int i = 0;
    linklist p = H, q;
    while (i < k-1)
    {
        p = p->next;
        i++;
    }
    printf("%d\n", p->data);
    while (p->next != p)
    {
        i = 0;
        while (i < m-2)
        {
            p = p->next;
            i++;
        }

        q = p->next;
        p->next = q->next;
        printf("%d ", q->data);
        free(q);
        q = NULL;
        p = p->next;
    }
    printf("%d\n", p->data);
}

int main()
{
    linklist H;
    H = linklist_create(8);

    linklist_show(H);
    jose(H, 3, 4);

    return 0;
}
