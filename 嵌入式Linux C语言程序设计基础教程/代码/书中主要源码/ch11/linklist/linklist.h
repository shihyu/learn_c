#ifndef linklist_H_
#define linklist_H_

typedef int datatype;

typedef struct node
{
    datatype data;
    struct node *next;
}listnode, *linklist;

linklist linklist_create();
int linklist_clear(linklist H);
int linklist_is_empty(linklist H);
int linklist_insert(linklist H, int pos, datatype value);
int linklist_order_insert(linklist H, datatype value);
int linklist_sort(linklist H);
int linklist_delete(linklist H, int pos);
int linklist_reverse(linklist H);
int linklist_show(linklist H);

#endif

