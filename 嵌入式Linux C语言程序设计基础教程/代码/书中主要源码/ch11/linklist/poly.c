#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int coef;
    int exp;
    struct node *next;
}listnode, *linklist;

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

int linklist_insert(linklist H, int coef, int exp)
{
    linklist p = H, q;

    while (p->next && p->next->exp < exp)
        p = p->next;

    q = (linklist)malloc(sizeof(listnode));
    if (q == NULL)
    {
        printf("malloc error\n");
        return -1;
    }
    q->coef = coef;
    q->exp = exp;
    q->next = p->next;
    p->next = q;

    return 0; 
}

int linklist_union(linklist H1, linklist H2)
{
    linklist p = H1->next, q = H2->next, r = H1, s;
    H1->next = NULL;


    while (p && q)
    {
        if (p->exp < q->exp)
        {
            r->next = p;

            p = p->next;
            r = r->next;
            r->next = NULL;
        }
        else if (p->exp == q->exp)
        {
            p->coef += q->coef;
            if (p->coef == 0)
            {
                printf("==0\n");
                s = p;
                p = p->next;
                free(s);
                s = NULL;
            }
            else
            {
                r->next = p;
                p = p->next;
                r = r->next;
                r->next = NULL;
            }

            s = q;
            q = q->next;
            free(s);
            s = NULL;

        }
        else
        {
            r->next = q;
            q = q->next;
            r = r->next;
            r->next = NULL;
        }
    }

    if (p)
        r->next = p;
    else
        r->next = q;

    return 0;

}

void linklist_show(linklist H)
{
    linklist p = H->next;

    while (p)
    {
        printf("(%d,%d)\n", p->coef, p->exp);
        p = p->next;
    }
}

int main()
{
    linklist H1, H2;
    int a[][2] = {{5, 0}, {2, 1}, {9, 4}, {3, 16}, {8, 8}, {-30, 27}};
    int b[][2] = {{23, 16}, {6, 1}, {-8, 8}, {11, 11}, {25, 25}, {27, 27}};
    int i, j;
    H1 = linklist_create();
    H2 = linklist_create();

    for (i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        linklist_insert(H1, a[i][0], a[i][1]);
            
    for (i = 0; i < sizeof(b)/sizeof(b[0]); i++)
        linklist_insert(H2, b[i][0], b[i][1]);

    linklist_show(H1);
    printf("\n");
    linklist_show(H2);

    printf("******\n");
    linklist_union(H1, H2);
    linklist_show(H1);
    return 0;
}
