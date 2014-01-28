#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

linklist linklist_create()
{
    linklist H;
    H = (linklist)malloc(sizeof(listnode));
    if (H == NULL)
    {
        printf("malloc error\n");
        return H;
    }
    H->next = NULL;

    return H;
}

int linklist_clear(linklist H)
{
    linklist p = H, q;

    printf("clear:");
    while (p->next)
    {
        q = p->next;
        p = p->next;
        printf("%d ", q->data);
        free(q);
        q = NULL;
    }
    printf("\n");

    return 0;
}

//1 empty
int linklist_is_empty(linklist H)
{
    if (H == NULL)
    {
        printf("list not exist\n");
        return -1;
    }
    return (H->next == NULL);
}

int linklist_insert(linklist H, int pos, datatype value)
{
    linklist p = H, q;

    if (H == NULL)
    {
        printf("list not exist\n");
        return -1;
    }

    if (pos < 0)
    {
        printf("insert pos invalid\n");
        return -1;
    }

    while (pos--)
    {
        p = p->next;
        if (p == NULL)
        {
            printf("insert pos invalid\n");
            return -1;
        }      
    }

    q = (linklist)malloc(sizeof(listnode));
    if (q == NULL)
    {
        printf("malloc error\n");
        return -1;
    }

    q->data = value; 
    q->next = p->next;
    p->next = q;

    return 0;
}

int linklist_order_insert(linklist H, datatype value)
{
    linklist p = H, q;

    if (H == NULL)
    {
        printf("list not exist\n");
        return -1;
    }

    while (p->next && value > p->next->data)
        p = p->next;

    q = (linklist)malloc(sizeof(listnode));
    if (q == NULL)
    {
        printf("malloc error\n");
        return -1;
    }
    q->data = value;
    q->next = p->next;
    p->next = q;

    return 0;
}

int linklist_sort(linklist H)
{
    linklist p = H->next, q;
    H->next = NULL;

    if (H == NULL)
    {
        printf("list not exist\n");
        return -1;
    }

    while (p)
    {
        q = p;
        p = p->next;
        linklist_order_insert(H, q->data);
    }

    return 0;
}

int linklist_delete(linklist H, int pos)
{
    linklist p = H, q;

    if (H == NULL)
    {
        printf("list not exist\n");
        return -1;
    }

    if (pos < 0)
    {
        printf("delete pos invalid\n");
        return -1;
    }

    while (pos--)
    {
        p = p->next;
        if (p == NULL)
        {
            printf("delete pos invalid\n");
            return -1;
        }      
    }

    if (p->next == NULL)
    {
        printf("delete pos invalid\n");
        return -1;
    }      

    q = p->next;
    p->next = q->next;
    free(q);
    q = NULL;

    return 0;
}

int linklist_reverse(linklist H)
{
    linklist p = H->next, q;
    H->next = NULL;

    if (H == NULL)
    {
        printf("list not exist\n");
        return -1;
    }

    while (p)
    {
        q = p;
        p = p->next;

        q->next = H->next;
        H->next = q;
    }
}

int linklist_show(linklist H)
{
    linklist p = H->next;

    if (H == NULL)
    {
        printf("list not exist\n");
        return -1;
    }

    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    return 0;
}
