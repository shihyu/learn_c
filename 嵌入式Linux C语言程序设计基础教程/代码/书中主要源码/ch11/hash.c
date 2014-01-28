#include <stdio.h>
#include <stdlib.h>

#define N 13

typedef struct node
{
    int data;
    struct node *next;
}listnode, *linklist;

int insert(linklist h, int key)
{
    int value = key % N;
    linklist p = &h[value], q;

    q = (linklist)malloc(sizeof(listnode));
    q->data = key;
    q->next = NULL;

    while (p->next && p->next->data < key)
        p = p->next;
    
    q->next = p->next;
    p->next = q;
    
    return 0;
}

int contains(linklist h, int key)
{
    int value = key % N;;
    linklist p = h[value].next;

    while (p)
    {
        if (p->data == key)
            return 0;
        p = p->next;
    }
    return -1;
}

void show(linklist p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    listnode hash[N] = {0, NULL};

    int a[] = {23, 34, 14, 38, 46, 16, 68, 15, 7, 31, 26}, i;

    for (i = 0; i < sizeof(a)/sizeof(int); i++)
        insert(hash, a[i]);

    for (i = 0; i < N; i++)
        show(hash[i].next);

    printf("** %d\n", contains(hash, 99));

    return 0;
}
