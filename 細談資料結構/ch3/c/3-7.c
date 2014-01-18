/*=========================================================

    第 3-7 節:

      CListTraverse(), CListLength(), CInsertTail();
  =========================================================
*/

#include    <stdio.h>
#include    <stdlib.h>

typedef struct tagListNode {
    int data;
    struct tagListNode* next;
} ListNode;
ListNode* listA;

int CInsertTail(ListNode*, int);
int CListLength(ListNode*);
void CListTraverse(ListNode*);
void CFreeAllNode(ListNode*);

void main(void) {
    FILE* fin;
    int insertdata, len;

    if ((fin = fopen("List.in", "r")) == NULL) {
        printf("File can not be opened, program terminate.");
        exit(1);
    }

    listA = (ListNode*)malloc(sizeof(ListNode));
    listA->next = listA; //a simple circle
    fscanf(fin, "%d", &insertdata);

    while (!feof(fin)) {
        CInsertTail(listA, insertdata);
        fscanf(fin, "%d", &insertdata);
    }

    fclose(fin);
    printf("\n The elements of the list are : \n");
    CListTraverse(listA);
    printf("\n ");
    len = CListLength(listA);
    printf("\n The length of the list is : %d \n", len);
    CFreeAllNode(listA);        /*釋放所有節點*/
    exit(0);            /*結束程式*/
}

void CListTraverse(ListNode* head) {
    ListNode*   p = head;
    p = p->next ;

    while (p != head) {
        printf("\n%d", p->data);
        p = p->next ;
    }
}
int CListLength(ListNode* head) {
    int   counter = 0 ;
    ListNode* p = head ;

    while ((p = p->next) != head) {
        counter ++ ;
    }

    return counter ;
}

int CInsertTail(ListNode* head, int value) {
    ListNode* new_node, *p = head;

    if ((new_node = (ListNode*)malloc(sizeof(ListNode))) == NULL) {
        return (0);
    }

    new_node->data = value;
    new_node->next = head;

    while (p->next != head) {
        p = p->next;
    }

    p->next = new_node;
    return (1);
}

void CFreeAllNode(ListNode* head) {
    ListNode* next_node, *ptr = head->next;

    while (ptr != head) {
        next_node = ptr->next;
        free(ptr);
        ptr = next_node;
    }
}

