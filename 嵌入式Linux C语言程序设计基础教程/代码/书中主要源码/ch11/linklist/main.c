#include <stdio.h>
#include "linklist.h"

int main()
{
    int a[5]= {273, 113, 93, 33, 43}, i;
    linklist L1;
    L1 = linklist_create();

    for (i = 0; i < 5; i++)
        linklist_insert(L1, i, a[i]);

    linklist_show(L1);
    linklist_reverse(L1);
    linklist_show(L1);
    linklist_sort(L1);
    linklist_show(L1);

    return 0;
}
